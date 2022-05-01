TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle

#since we want to use qDebug, we
#will not subtract qt.
#CONFIG -= qt

CONFIG += c++11
#------------------------------------------
##Add these lines for SFML:



#WINDOWS
# put SFML file in the same location as project
#LIBS += -L"..\..\SFML-2.5.1\lib" #change this
#LIBS += -L"..\..\SFML-2.5.1\bin" #change this

#MAC
LIBS += -L"/usr/local/lib"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug  , debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

#WINDOWS
#INCLUDEPATH += "..\..\SFML-2.5.1\include" #change this
#DEPENDPATH  += "..\..\SFML-2.5.1\include" #change this

#MAC
INCLUDEPATH += "/usr/local/include"
DEPENDPATH += "/usr/local/include"

#-----------------------------------------

SOURCES += main.cpp \
    system.cpp \
    random.cpp \
    sidebar.cpp \
    animate.cpp \
    graph_info.cpp \
    plot.cpp \
    ../../Ch.15/Shunting_Yard/15_07_RPN_Shunting_Yard/rpn.cpp \
    ../../Ch.15/Shunting_Yard/15_07_RPN_Shunting_Yard/variable.cpp \
    ../../Ch.15/Shunting_Yard/15_07_RPN_Shunting_Yard/shunting_yard.cpp \
    ../../Ch.15/Shunting_Yard/15_07_RPN_Shunting_Yard/integer_number.cpp \
    ../../Ch.15/Shunting_Yard/15_07_RPN_Shunting_Yard/operator.cpp \
    ../../Ch.15/Shunting_Yard/15_07_RPN_Shunting_Yard/token.cpp \
    ../../Ch.15/Shunting_Yard/15_07_RPN_Shunting_Yard/function.cpp \
    ../../Ch.15/Shunting_Yard/15_07_RPN_Shunting_Yard/left_p.cpp \
    ../../Ch.15/Shunting_Yard/15_07_RPN_Shunting_Yard/right_p.cpp \
    ../../Ch.15/Shunting_Yard/15_07_RPN_Shunting_Yard/tokenize.cpp


HEADERS += \
    constants.h \
    system.h \
    random.h \
    sidebar.h \
    animate.h \
    graph_info.h \
    plot.h \
    ../../Ch.15/Shunting_Yard/15_07_RPN_Shunting_Yard/rpn.h \
    ../../Ch.15/Shunting_Yard/15_07_RPN_Shunting_Yard/variable.h \
    ../../Ch.15/Shunting_Yard/15_07_RPN_Shunting_Yard/shunting_yard.h \
    ../../Ch.15/Shunting_Yard/15_07_RPN_Shunting_Yard/integer_number.h \
    ../../Ch.15/Shunting_Yard/15_07_RPN_Shunting_Yard/operator.h \
    ../../Ch.15/Shunting_Yard/15_07_RPN_Shunting_Yard/token.h \
    ../../Ch.15/Shunting_Yard/15_07_RPN_Shunting_Yard/function.h \
    ../../Ch.15/Shunting_Yard/15_07_RPN_Shunting_Yard/left_p.h \
    ../../Ch.15/Shunting_Yard/15_07_RPN_Shunting_Yard/right_p.h \
    ../../Ch.15/Shunting_Yard/15_07_RPN_Shunting_Yard/tokenize.h \
    description.h
