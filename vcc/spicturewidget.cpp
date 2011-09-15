/*
 * File:      spicturewidget.cpp
 * Author:    Bardia Daneshvar (bardia@getsilicon.org)
 * Copyright: (C) 2010 Bardia Daneshvar
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License
 * for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "spicturewidget.h"

#include <QImage>
#include <QPainter>
#include <QImageReader>
#include <QThreadPool>
#include <QTimer>



/*================================*
 |                                |
 |    THCoverFlowImageLoader      |
 |                                |
 *================================*/

THCoverFlowImageLoader::THCoverFlowImageLoader ()
    : QThread()
{
    run_status = false;
}

THCoverFlowImageLoader::THCoverFlowImageLoader (const QImage& image)
{
    this->setImage( image );
    run_status = false;
}

THCoverFlowImageLoader::THCoverFlowImageLoader (const QString& path)
{
    this->setPath( path );
    run_status = false;
}

THCoverFlowImageLoader::~THCoverFlowImageLoader()
{
}

void THCoverFlowImageLoader::setImage( const QImage & image )
{
    m_image = image;
    m_path = QString();
}

void THCoverFlowImageLoader::setPath( const QString & path )
{
    m_image = QImage();
    m_path = path;
}

void THCoverFlowImageLoader::setSize( const QSize & size )
{
    m_size = size;
}

bool THCoverFlowImageLoader::isRunning()
{
    return run_status;
}

void THCoverFlowImageLoader::run ()
{
    run_status = true;
    if(!m_path.isEmpty())
    {
        QImageReader reader(m_path);
        reader.setScaledSize(QSize(m_size.width(), m_size.height()));
        m_image = reader.read();
    }
    else if(!m_image.isNull())
    {
        m_image = m_image.scaled(m_size.width(), m_size.height(),Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    }
    run_status = false;

    emit completed(m_image);
}



/*================================*
 |                                |
 |     SPictureWidgetPrivate      |
 |                                |
 *================================*/

class SPictureWidgetPrivate
{
public:
    ~SPictureWidgetPrivate()
    {
        cover_flow->terminate();

        delete cover_flow;
    }

    QTimer *resize_timer;
    int resize_timer_ms;

    QString picture_path;
    QImage image;
    QImage original_image;
    QRect current_paint_rect;
    bool auto_size_stt;
    bool keep_proportion_stt;
    bool is_button_stt;
    bool is_checkable_stt;
    bool check_stt;
    bool reload_force;
    bool progress_indicator_stt;
    bool clear_on_loading;
    bool check_board_stt;

    double padding_top_ratio;
    double padding_left_ratio;
    int padding_top_steps;
    int padding_left_steps;

    int mouse_over_opacity_int;

    THCoverFlowImageLoader *cover_flow;
};



/*================================*
 |                                |
 |         SPictureWidget         |
 |                                |
 *================================*/

SPictureWidget::SPictureWidget(QWidget *parent) : QWidget( parent )
{
    p = new SPictureWidgetPrivate;

    p->auto_size_stt = false;
    p->keep_proportion_stt = true;
    p->is_button_stt = false;
    p->is_checkable_stt = false;
    p->check_stt = false;
    p->reload_force = false;
    p->progress_indicator_stt = false;
    p->clear_on_loading = true;
    p->check_board_stt = false;

    p->padding_top_ratio = 1;
    p->padding_left_ratio = 1;

    p->padding_top_steps = 50;
    p->padding_left_steps = 50;

    p->mouse_over_opacity_int = 37;

    p->resize_timer_ms = 0;
    p->cover_flow = 0;

    p->cover_flow = new THCoverFlowImageLoader();
    p->resize_timer = new QTimer(this);
        p->resize_timer->setSingleShot( true );

    QObject::connect( p->cover_flow , SIGNAL(completed(QImage)) , this , SLOT(scaled_ready(QImage)) , Qt::QueuedConnection );
    QObject::connect( p->resize_timer , SIGNAL(timeout()) , this , SLOT(repaint()) );
}

void SPictureWidget::drawIcon( const QIcon & icon , const QSize & size )
{
    this->drawPixmap( icon.pixmap(size) );
}

void SPictureWidget::drawFile(const QString & fileName)
{
    p->picture_path = fileName;
    p->reload_force = true;
    p->clear_on_loading = true;

    p->current_paint_rect.setSize( QImageReader(p->picture_path).size() );
    p->cover_flow->setPath( p->picture_path );
    this->update();
}

void SPictureWidget::drawPixmap(const QPixmap & pixmap)
{
    this->drawImage( pixmap.toImage() );
}

void SPictureWidget::drawImage( const QImage & image )
{
    p->picture_path.clear();

    p->reload_force = true;
    p->clear_on_loading = true;
    p->image = image;
    p->original_image = p->image;
    p->current_paint_rect.setSize( image.size() );
    p->cover_flow->setImage( image );
    this->update();
}

void SPictureWidget::drawNothing()
{
    p->picture_path.clear();

    p->reload_force = true;
    p->clear_on_loading = true;
    p->image = QImage() ;
    p->original_image = p->image;
    p->current_paint_rect.setSize( p->image.size() );
    this->update();
}

void SPictureWidget::setAutoSize( bool stt )
{
    p->auto_size_stt = stt;

    if( p->auto_size_stt )
        this->setKeepProportion( false );

    this->update();
}

void SPictureWidget::setKeepProportion( bool stt )
{
    p->keep_proportion_stt = stt;

    if( p->keep_proportion_stt )
        this->setAutoSize( false );

    this->update();
}

void SPictureWidget::process_anim()
{

}

void SPictureWidget::scaled_ready( const QPixmap & pixmap )
{
    this->scaled_ready( pixmap.toImage() );
}

void SPictureWidget::scaled_ready( const QImage & image )
{
    p->image = image;
    p->clear_on_loading = true;

    this->repaint();
}

void SPictureWidget::setButton( bool stt )
{
    p->is_button_stt = stt;
}

void SPictureWidget::setCheckable( bool stt )
{
    p->is_checkable_stt = stt;
}

void SPictureWidget::setChecked( bool stt )
{
    p->check_stt = stt;
    if( p->check_stt )
    {
        QColor color = this->palette().highlight().color();
            color.setAlpha( 100 );

        QPalette palette = this->palette();
            palette.setColor( QPalette::Window , color );

        this->setAutoFillBackground( true );
        this->setPalette( palette );
    }
    else
    {
        QColor color = this->palette().color( QPalette::Base );
            color.setAlpha( 0 );

        QPalette palette = this->palette();
            palette.setColor( QPalette::Window , color );

        this->setAutoFillBackground( false );
        this->setPalette( palette );
    }

    emit this->checked( stt );
}

void SPictureWidget::setMouseOverOpacity( int value )
{
    p->mouse_over_opacity_int = value;
}

bool SPictureWidget::isAutoSize() const
{
    return p->auto_size_stt;
}

bool SPictureWidget::isKeepProportion() const
{
    return p->keep_proportion_stt;
}

bool SPictureWidget::isButton() const
{
    return p->is_button_stt;
}

bool SPictureWidget::isCheckable() const
{
    return p->is_checkable_stt;
}

bool SPictureWidget::isChecked() const
{
    return p->check_stt;
}

int SPictureWidget::mouseOverOpacity() const
{
    return p->mouse_over_opacity_int;
}

void SPictureWidget::click()
{
    if( !p->is_button_stt )
        return ;

    if( p->is_checkable_stt )
        this->setChecked( !p->check_stt );

    emit this->clicked();
    emit this->clicked( this );
}

const QString & SPictureWidget::currentPath() const
{
    return p->picture_path;
}

QPixmap SPictureWidget::currentPixmap() const
{
    return QPixmap::fromImage( p->image );
}

QImage SPictureWidget::currentImage() const
{
    return p->image;
}

QSize SPictureWidget::drawedSize() const
{
    return p->current_paint_rect.size();
}

void SPictureWidget::setReloadAfterResize( int ms )
{
    p->resize_timer_ms = ms;
}

int SPictureWidget::reloadAfterResize() const
{
    return p->resize_timer_ms;
}

void SPictureWidget::setCheckBoard( bool stt )
{
    p->check_board_stt = stt;
}

void SPictureWidget::paintEvent(QPaintEvent *)
{
    QRect rct = this->rect();

    QSize original_image_size;
    if( p->picture_path.isEmpty() )
        original_image_size = p->original_image.size();
    else
        original_image_size = QImageReader(p->picture_path).size();

    if( p->keep_proportion_stt )
    {
        int height = this->height()
           ,width = this->width();
        double proportion = (double)original_image_size.height() / (double)original_image_size.width();

        if( height > width*proportion )
        {
            int h = width*proportion
               ,t = (height - h)/2;

            rct.setHeight( h + t );
            rct.setTop( t );
        }
        else
        {
            int w = height/proportion
               ,l = (width - w)/2;

            rct.setWidth( w + l );
            rct.setLeft( l );
        }
    }
/*
    if( rct.height() > p->current_paint_rect.height() || rct.width() > p->current_paint_rect.width() )
        if( p->picture_path.isEmpty() )
            p->image = p->original_image;
*/
    if( p->image.isNull() && p->picture_path.isEmpty() )
        return ;

    if( (rct.size() != p->image.size() && !p->resize_timer->isActive()) || p->reload_force   )
    {
        p->cover_flow->setSize( rct.size() );
        p->cover_flow->start();

        p->reload_force = false;

        if( p->clear_on_loading )
            return ;
    }

    QColor color = QPalette().color(QPalette::Highlight);
        color.setAlpha( 73 * p->check_stt );

    QPainter painter(this);
        painter.setRenderHint( QPainter::SmoothPixmapTransform , true );
        painter.drawImage( rct , p->image );
        painter.fillRect( rct , color );


    p->current_paint_rect = rct;
    if( p->cover_flow->isFinished() )
        emit this->drawed();
}

void SPictureWidget::mouseReleaseEvent( QMouseEvent * )
{
    this->click();
}

void SPictureWidget::enterEvent( QEvent * )
{
    if( !p->is_button_stt || p->check_stt )
        return ;

    QColor color = this->palette().highlight().color();
        color.setAlpha( p->mouse_over_opacity_int );

    QPalette palette = this->palette();
        palette.setColor( QPalette::Window , color );

    this->setAutoFillBackground( true );
    this->setPalette( palette );
}

void SPictureWidget::leaveEvent( QEvent * )
{
    if( !p->is_button_stt || p->check_stt )
        return ;

    QColor color = this->palette().color( QPalette::Base );
        color.setAlpha( 0 );

    QPalette palette = this->palette();
        palette.setColor( QPalette::Window , color );

    this->setAutoFillBackground( false );
    this->setPalette( palette );
}

void SPictureWidget::resizeEvent( QResizeEvent * )
{
    if( p->resize_timer_ms == 0 )
        return ;

    p->clear_on_loading = false;
    p->resize_timer->stop();
    p->resize_timer->start( p->resize_timer_ms );
}

SPictureWidget::~SPictureWidget()
{
    delete p;
}
