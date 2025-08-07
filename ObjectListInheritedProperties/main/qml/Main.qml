import QtQuick
import ObjectListInheritedProperties

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Object list inherited properties")

    FootBallTeam {
        id: footballTeamId
        title: "Rayon sport"
        coach: "Coatch name"
        captain: Stricker {
            name: "Captain"
            position: "Middle field"
            isPlaying: true
        }

        players: [
            Defender {
                name: "Defender 1"
                position: "Middle field"
                isPlaying: true
            }
            , Stricker {
                name: "Stricker 1"
                position: "Middle field"
                isPlaying: true
            }
            , Defender {
                name: "Defender 2"
                position: "Middle Field"
                isPlaying: true
            }, Stricker {
                name: "Stricker 2"
                position: "Middle Field"
                isPlaying: true
            }
        ]
    }

    ListView {
        id: playerListViewId
        anchors.fill: parent
        model: footballTeamId.players
        delegate: Rectangle {
            width: parent.width
            height: 50
            border.width: 1
            border.color: "yellowgreen"
            color: "beige"

            Text {
                anchors.centerIn: parent
                text: name
                font.pointSize: 20
            }

            Text {
                text: position
                font.pointSize: 10
            }
        }
    }

    Component.onCompleted: function() {
        console.log("We have: " + footballTeamId.players.length + " players in the team named: " + footballTeamId.title)
    }
}
