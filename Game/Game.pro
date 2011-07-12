#-------------------------------------------------
#
# Project created by QtCreator 2010-12-22T16:44:30
#
#-------------------------------------------------

QT       += core gui opengl xml

TARGET = Game

TEMPLATE = app


#QMAKE_CXXFLAGS += -pg

SOURCES += main.cpp\
				mainwindow.cpp \
		glwidget.cpp \
		graphis/graphicsobject.cpp \
		qtshader.cpp \
		globject.cpp \
		clandobject.cpp \
		runtime/cxmlbind.cpp \
		runtime/gameobject.cpp \
		runtime/gameobjectclass.cpp \
		runtime/gameclasses.cpp \
		dataCtrl/materials.cpp \
		game/selectrect.cpp \
		game/objectcollection.cpp \
		game/abstractbehavior.cpp \
		game/unitbehavior.cpp \
		game/map.cpp \
		game/game.cpp \
		hud/cyrcle.cpp \
		game/control/unitctrl.cpp \
		widgets/unitsgroup.cpp \
		game/movealgo.cpp \
		game/workerbehavior.cpp \
		game/behaviorcollection.cpp \
		game/resourcebehavior.cpp \
		game/playler.cpp \
		game/centralbuildingbehavior.cpp \
		game/control/castlecontrol.cpp \
		game/ui/buybutton.cpp \
		game/buildingbehavior.cpp \
		dataCtrl/filestream.cpp \
		fun/bmpmap.cpp \
		graphis/gamescene.cpp \
		graphis/gamescenegraph.cpp \
		game/control/workercontroller.cpp \
		game/incompletebuildingbehavior.cpp \
		dataCtrl/pixmaps.cpp \
		runtime/hotkeys.cpp \
		dialogs/saveloaddialog.cpp \
		hud/screenhudrender.cpp \
		runtime/texturefactory.cpp \
		game/control/incompletebuildingcontrol.cpp \
		game/warriorbehavior.cpp \
		manwidget.cpp \
		game/ai/bot.cpp \
		hud/minimap.cpp \
		runtime/atacktypes.cpp \
		game/utils/unitscounter.cpp \
		hud/unitavatar.cpp \
		widgets/unitbutton.cpp \
		game/utils/spatialindex.cpp \
		hud/showhint.cpp \
		game/utils/randomgen.cpp \
		sound/sound.cpp \
		graphis/renderalgo.cpp \
		graphis/rendermainpass.cpp \
		graphis/landtechnicue.cpp \
		graphis/abstractuserpass.cpp \
		graphis/virtualtexturingpass.cpp \
		graphis/adapter.cpp \
		settingswidget.cpp \
		runtime/soundgroup.cpp \
		graphis/bulletobject.cpp \
		log.cpp \
		widgets/startffawidget.cpp \
		widgets/mapfilewidget.cpp \
		widgets/playlersettings.cpp \
		widgets/showwidget.cpp \
		graphis/view.cpp \
		game/falagownerbahavior.cpp \
		style/norwegianwoodstyle.cpp \
		style/cursors.cpp \
		widgets/gamewidget.cpp \
    graphis/deathanimation.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    graphis/graphicsobject.h \
    qtshader.h \
    globject.h \
    clandobject.h \
    runtime/cxmlbind.h \
    runtime/gameobject.h \
    runtime/gameobjectclass.h \
    runtime/gameclasses.h \
    dataCtrl/materials.h \
    game/selectrect.h \
    game/objectcollection.h \
    game/abstractbehavior.h \
    game/unitbehavior.h \
    game/map.h \
    game/game.h \
    hud/cyrcle.h \
    widgets/unitsgroup.h \
    game/movealgo.h \
    game/workerbehavior.h \
    game/behaviorcollection.h \
    game/resourcebehavior.h \
    game/playler.h \
    game/centralbuildingbehavior.h \
    game/control/unitctrl.h \
    game/control/icontroller.h \
    game/control/castlecontrol.h \
    game/ui/buybutton.h \
    game/buildingbehavior.h \
    dataCtrl/filestream.h \
    fun/bmpmap.h \
    graphis/gamescene.h \
    graphis/gamescenegraph.h \
    game/control/workercontroller.h \
    game/incompletebuildingbehavior.h \
    dataCtrl/pixmaps.h \
    runtime/hotkeys.h \
    dialogs/saveloaddialog.h \
    hud/screenhudrender.h \
    runtime/texturefactory.h \
    game/control/incompletebuildingcontrol.h \
    game/warriorbehavior.h \
    manwidget.h \
    game/ai/bot.h \
    hud/minimap.h \
    runtime/atacktypes.h \
    game/utils/unitscounter.h \
    hud/unitavatar.h \
    widgets/unitbutton.h \
    game/utils/spatialindex.h \
    hud/showhint.h \
    game/utils/randomgen.h \
    sound/sound.h \
    graphis/renderalgo.h \
    graphis/rendermainpass.h \
    graphis/landtechnicue.h \
    graphis/abstractuserpass.h \
    graphis/virtualtexturingpass.h \
    graphis/adapter.h \
    settingswidget.h \
    runtime/soundgroup.h \
    graphis/bulletobject.h \
    game/utils/stableset.h \
    log.h \
    widgets/startffawidget.h \
    widgets/mapfilewidget.h \
    widgets/playlersettings.h \
    widgets/showwidget.h \
    graphis/view.h \
    game/falagownerbahavior.h \
    style/norwegianwoodstyle.h \
    style/cursors.h \
    widgets/gamewidget.h \
    graphis/deathanimation.h

FORMS    += mainwindow.ui \
    widgets/unitsgroup.ui \
    game/control/unitctrl.ui \
    game/control/castlecontrol.ui \
    game/control/workercontroller.ui \
    dialogs/saveloaddialog.ui \
    game/control/incompletebuildingcontrol.ui \
    manwidget.ui \
    hud/minimap.ui \
    hud/unitavatar.ui \
    settingswidget.ui \
    widgets/startffawidget.ui \
    widgets/playlersettings.ui \
    widgets/gamewidget.ui

INCLUDEPATH += ../MyGL_XmlData/include
win32: LIBS += -L"../MyGL_XmlData-build-desktop/release" -l"MyGL_XmlData"
unix:  LIBS += -L"../MyGL_XmlData-build-desktop" -l"MyGL_XmlData"

INCLUDEPATH += ../MyGL/include
win32: LIBS += -L"../MyGL-build-desktop/release" -l"MyGL"
unix:  LIBS += -L"../MyGL-build-desktop" -l"MyGL"

win32: LIBS += -l"OpenGL32" -l"glu32"

OTHER_FILES += \
    ../Game-build-desktop/data/data.xml \
    ../Game-build-desktop/game/game.xml \
    ../Game-build-desktop/game/units.xml \
    ../Game-build-desktop/game/buildings.xml \
    ../Game-build-desktop/game/hud.xml \
    ../Game-build-desktop/log.txt \
    ../Game-build-desktop/pixmaps/pixmaps.xml \
    ../Game-build-desktop/game/atack_types.xml \
    ../Game-build-desktop/shaders/depth.vert \
    ../Game-build-desktop/shaders/depth.frag \
    ../Game-build-desktop/game/upgrades.xml \
    ../Game-build-desktop/settings/settings.xml \
    ../Game-build-desktop/game/help_sys.xml \
    ../Game-build-desktop/game/bullets.xml \
    ../Game-build-desktop/game/trees.xml \
    ../Game-build-desktop/data/trees/trees.xml \
    ../Game-build-desktop/data/crystals/crystals.xml \
    ../Game-build-desktop/game/crystals.xml
