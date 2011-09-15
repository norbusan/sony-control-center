/*
 * File:      spicturewidget.h
 * Author:    Bardia Daneshvar (bardia@getsilicon.org)
 * Copyright: (C) 2010 Bardia Daneshvar
 * Main Project : Silicon Empire : http://getSilicon.org
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

#ifndef SPICTUREWIDGET_H
#define SPICTUREWIDGET_H

#include <QWidget>
#include <QObject>
#include <QPaintEngine>
#include <QPaintEvent>
#include <QResizeEvent>
#include <QRectF>
#include <QPoint>
#include <QSize>
#include <QIcon>
#include <QImage>
#include <QThread>

/*! \class
 * The THCoverFlowImageLoader provides a class to read and load
 * picture from file in another thread.
 * This Class is part of MokoTouch and now Edited by
 * Bardia Daneshvar to use in the SPictureWidget class.
 */
class THCoverFlowImageLoader : public QThread
{

/*
 * This class is part of MokoTouch.
 *
 * MokoTouch is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * MokoTouch is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with MokoTouch.  If not, see <http://www.gnu.org/licenses/>.
 */

    Q_OBJECT
public:
    THCoverFlowImageLoader ();
    THCoverFlowImageLoader (const QImage& image);
    THCoverFlowImageLoader (const QString& path);
    ~THCoverFlowImageLoader();

    void setImage( const QImage & image );
    void setPath( const QString & path );

    void setSize( const QSize & size );
    void run (void);

    bool isRunning();

Q_SIGNALS:
    void completed (const QImage& image);

private:
    QString m_path;
    QImage m_image;
    QSize m_size;

    bool run_status;
};






class SPictureWidgetPrivate;

/*! \class
 * The SPictureWidget provides a class to draw images on
 * a widget.
 */
class SPictureWidget : public QWidget
{

/*! List of All Available Functions :
 *
 * PUBLIC FUNCTIONS:
 *     SPictureWidget(QWidget *parent = 0);
 *     ~SPictureWidget();
 *
 *     void drawIcon( const QIcon & icon , const QSize & size );
 *     void drawImage( const QImage & image );
 *     void drawPixmap( const QPixmap & pixmap );
 *     void drawFile( const QString & fileName );
 *     void drawNothing();
 *
 *     void setAutoSize( bool stt );
 *     bool isAutoSize() const;
 *
 *     void setKeepProportion( bool stt );
 *     bool isKeepProportion() const;
 *
 *     void setButton( bool stt );
 *     bool isButton() const;
 *
 *     void setCheckable( bool stt );
 *     bool isCheckable() const;
 *
 *     void setChecked( bool stt );
 *     bool isChecked() const;
 *
 *     void setMouseOverOpacity( int value );
 *     int mouseOverOpacity() const;
 *
 *     void setShowProgressIndicator( bool stt );
 *     void click() const;
 *
 *     const QString & currentPath() const;
 *     QPixmap currentPixmap() const;
 *     QImage currentImage() const;
 *
 *     QSize drawedSize() const;
 *
 *     void setReloadAfterResize( int ms );
 *     int reloadAfterResize() const;
 *
 * SIGNALS:
 *     void clicked();
 *     void clicked( SPictureWidget *picture_widget );
 *     void checked( bool stt );
 *     void drawed();
 *
 */

    Q_OBJECT
    Q_DISABLE_COPY( SPictureWidget )

public:
    /*!
     * Constructs a Picture Widget with "*parent" parent.
     */
    SPictureWidget(QWidget *parent = 0);
    ~SPictureWidget();


    /*!
     *  Draws "icon" icon in "size" size on the Picture Widget.
     * \sa drawImage
     */
    void drawIcon( const QIcon & icon , const QSize & size );

    /*!
     *  Draws "image" image on the Picture Widget.
     * \sa drawPixmap
     */
    void drawImage( const QImage & image );

    /*!
     *  Draws "pixmap" pixmap on the Picture Widget.
     * \sa drawFile
     */
    void drawPixmap( const QPixmap & pixmap );

    /*!
     *  Draws "fileName" image file on the Picture Widget.
     * \sa drawNothing
     */
    void drawFile( const QString & fileName );

    /*!
     * Clear widget from any picture and image.
     * \sa drawIcon
     */
    void drawNothing();


    /*!
     * When AutoResize is active, the Picture Widget Automatically
     * resize drawed image when widget resized.
     * \sa setKeepProportion
     */
    void setAutoSize( bool stt );
    bool isAutoSize() const;


    /*!
     * When KeepProportion is active, the Picture Widget Automatically
     * keep propertions of height and width of the drawed picture.
     * \sa setAutoSize
     */
    void setKeepProportion( bool stt );
    bool isKeepProportion() const;


    /*!
     * Set Picture Widget to clickable like a push button.
     * \sa setCheckable
     * \sa clicked
     */
    void setButton( bool stt );
    bool isButton() const;


    /*!
     * Set Picture Widget Checkable.
     * This option take effect when button mod is activated.
     * \sa setButton
     * \sa setChecked
     * \sa checked
     */
    void setCheckable( bool stt );
    bool isCheckable() const;


    /*!
     * When the Picture Widget is checkable and checked this
     * function Returns true , else return false.
     * \sa setCheckable
     * \sa checked
     */
    void setChecked( bool stt );
    bool isChecked() const;


    /*!
     * Set Mouse Over Opacity of Button.
     * Button mode must be activated.
     * \sa setButton
     */
    void setMouseOverOpacity( int value );
    int mouseOverOpacity() const;


    /*!
     * If ProgressIndicator is active , when the PictureWidget
     * drawing an image , progress indicator showing.
     */
    void setShowProgressIndicator( bool stt );


    /*!
     * Performs a click on PictureWidget.
     * Button mode must be activated.
     * \sa setButton
     */
    void click();


    /*!
     * Returns current drawed File Path , Pixmap or image.
     * \sa drawImage
     * \sa drawFile
     * \sa drawPixmap
     */
    const QString & currentPath() const;
    QPixmap currentPixmap() const;
    QImage currentImage() const;


    /*!
     * Returns Drawed Size of Image , Pixmap , file or icon.
     * \sa drawFile
     */
    QSize drawedSize() const;


    /*!
     * Reloading or Redrawing your image when the widget resizing
     * after "ms" mili second.
     * If ms=0 this feature set to disable.
     */
    void setReloadAfterResize( int ms );
    int reloadAfterResize() const;


    void setCheckBoard( bool stt );

signals:
    /*!
     * This Signal emitted when user clicked on PictureWidget.
     * Button mode must be activated.
     * \sa setButton
     * \sa click
     */
    void clicked();
    void clicked( SPictureWidget *picture_widget );


    /*!
     * This Signal emitted when PictureWidget ckeck status changed.
     * Checkable mode must be activated.
     * \sa setCheckable
     * \sa setChecked
     */
    void checked( bool stt );


    /*!
     * This Signal emitted when file, pixmap or icon drawed
     * successfully on widget.
     * \sa drawFile
     * \sa drawPixmap
     * \sa drawIcon
     */
    void drawed();

private slots:
    void process_anim();
    void scaled_ready( const QImage & image );
    void scaled_ready( const QPixmap & pixmap );

protected:
    void paintEvent( QPaintEvent *event );
    void mouseReleaseEvent( QMouseEvent *event );
    void enterEvent( QEvent *event );
    void leaveEvent( QEvent *event );
    void resizeEvent( QResizeEvent *event );

private:
    SPictureWidgetPrivate *p;
};

#endif // SPICTUREWIDGET_H
