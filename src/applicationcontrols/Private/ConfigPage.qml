import QtQuick 2.1
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1
import QtQuick.Window 2.0
import Machinekit.Controls 1.0

Item {
    property bool autoSelectApplication: false
    property bool localVisible: true
    property bool remoteVisible: true
    property string mode: "local"
    property var configService: {"name": "Test on XYZ"}

    signal applicationSelected(int index)
    signal goBack()

    id: root

    Label {
        id: dummyText
        visible: false
    }
    Button {
        id: dummyButton
        visible: false
    }

    Component {
        id: localRemoteContent

        ColumnLayout {
            spacing: Screen.logicalPixelDensity*3

            Label {
                id: pageTitleText

                Layout.fillWidth: true
                text: configService.name
                font.pointSize: dummyText.font.pointSize * 1.3
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
                wrapMode: Text.WordWrap

                RowLayout {
                    anchors.fill: parent

                    Item { Layout.fillWidth: true }
                    Button {
                        text: qsTr("Back")
                        onClicked: goBack()
                    }
                }
            }

            ListView {
                Layout.fillWidth: true
                Layout.fillHeight: true
                spacing: Screen.logicalPixelDensity*3
                clip: true

                model: (root.mode == "local") ? applications : applicationConfig.configs
                delegate: Button {
                    anchors.left: parent.left
                    anchors.right: parent.right
                    height: dummyButton.height * 3

                    ColumnLayout {
                        anchors.left: parent.left
                        anchors.right: parent.right
                        anchors.verticalCenter: parent.verticalCenter

                        Label {
                            id: titleText

                            Layout.fillWidth: true
                            font.pointSize: dummyText.font.pointSize*1.3
                            font.bold: true
                            text: name
                            horizontalAlignment: Text.AlignHCenter
                            elide: Text.ElideRight
                        }
                        Label {
                            id: descriptionText

                            Layout.fillWidth: true
                            text: description
                            color: systemPalette.dark
                            horizontalAlignment: Text.AlignHCenter
                            wrapMode: Text.WordWrap
                        }
                    }

                    onClicked: applicationSelected(index)
                }

                onCountChanged: {
                    if (root.visible && (autoSelectApplication == true) && (count > 0))
                    {
                        applicationSelected(0)
                    }
                }
            }
        }
    }

    SlideView {
        id: appView
        anchors.fill: parent

        onCurrentIndexChanged: {
            if (currentIndex == 0)
                root.mode = "remote"
            else
                root.mode = "local"
        }

        Binding {
            target: appView; property: "currentIndex";
            value: ((root.mode == "remote") ? 0 : 1)
        }

        SlidePage {
            anchors.fill: parent
            anchors.margins: Screen.logicalPixelDensity*3
            title: qsTr("Remote")
            visible: root.remoteVisible

            Loader {
                anchors.fill: parent
                sourceComponent: localRemoteContent
                active: true
            }
        }

        SlidePage {
            anchors.fill: parent
            anchors.margins: Screen.logicalPixelDensity*3
            title: qsTr("Local")
            visible: root.localVisible

            Loader {
                anchors.fill: parent
                sourceComponent: localRemoteContent
                active: true
            }
        }
    }
}

