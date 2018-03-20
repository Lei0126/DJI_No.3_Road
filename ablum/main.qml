import QtQuick 2.8
import QtQuick.Window 2.2
import QtMultimedia 5.8

Item {
    id: window
    visible: true
    width: Screen.width
    height: Screen.height
    Camera {
        id: camera
        imageProcessing.whiteBalanceMode: CameraImageProcessing.WhiteBalanceAuto
        exposure {
            exposureCompensation: -1.0
            exposureMode: Camera.ExposurePortrait
        }
        flash.mode: Camera.FlashRedEyeReduction
        imageCapture {
            onImageCaptured: {
                photoPreview.source = preview  // Show the preview in an Image
            }
        }
    }

    VideoOutput {
        id:videoOut
        source: camera
        anchors.fill: parent
        autoOrientation:true;
        focus : visible // to receive focus and capture key events when visible
    }
}
