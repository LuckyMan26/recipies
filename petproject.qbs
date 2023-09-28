import qbs
CppApplication {
    Depends { name: "Qt.quick"}
    install: true
    // Additional import path used to resolve QML modules in Qt Creator's code model
    property pathList qmlImportPaths: []

    files: [
        "a.cpp",
        "a.h",
        "client.cpp",
        "client.h",
        "main.cpp",
        "server.cpp",
        "server.h",
    ]

    Group {
        Qt.core.resourcePrefix: "petProject/"
        fileTags: ["qt.qml.qml", "qt.core.resource_data"]
        files: ["Main.qml"]
    }
}
