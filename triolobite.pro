SOURCES += \
    main.cpp \
    piece.cpp \
    pieces.cpp \
    game.cpp \
    grid.cpp

CONFIG += c++17
QMAKE_CXXFLAGS += -std=c++17

# Be vigilant
QMAKE_CXXFLAGS += -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic

# Be strict
QMAKE_CXXFLAGS += -Werror

# Debug and release settings
CONFIG += debug_and_release
CONFIG(release, debug|release) {
  DEFINES += NDEBUG
}

# Qt5
QT += core gui

HEADERS += \
    piece.h \
    pieces.h \
    game.h \
    grid.h
