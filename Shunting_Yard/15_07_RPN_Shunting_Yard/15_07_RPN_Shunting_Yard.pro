TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    token.cpp \
    rpn.cpp \
    integer_number.cpp \
    operator.cpp \
    variable.cpp \
    shunting_yard.cpp \
    function.cpp \
    left_p.cpp \
    right_p.cpp \
    tokenize.cpp

HEADERS += \
    token.h \
    rpn.h \
    integer_number.h \
    operator.h \
    ../../../Ch.13/Stack_and_Queue/Stack_and_Queue/queue.h \
    ../../../Ch.13/Stack_and_Queue/Stack_and_Queue/stack.h \
    variable.h \
    shunting_yard.h \
    z.output.h \
    z_work_report.h \
    function.h \
    left_p.h \
    right_p.h \
    tokenize.h
