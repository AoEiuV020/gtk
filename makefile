#***************************************************
#	^> File Name: single.mk
#	^> Author: AoEiuV020
#	^> Mail: 490674483@qq.com
#	^> Created Time: 2015/05/09
#***************************************************
#######�Զ����뵱ǰ�ļ���������.cpp������.o�Ϳ�ִ���ļ���
#######���C=CC�����.c,
#######���RELEASE=1��ͬʱ���ɶ�Ӧ.a��.so,
#######�Զ��жϲ���ϵͳ
#ifeq ($(shell uname 2>&1),Linux)
#	WINDOWS=0
#else
#	WINDOWS=1
#endif
WINDOWS=0
#######�������ж�ϵͳ�ǲ���WINDOWS,׼��׼����ν�ˣ����þͺá�����
ifeq ($(WINDOWS),1)
	SHELL=cmd.exe
	TAREXT=exe
	RUN=
	RM=del /f
else
	TAREXT=out
	RUN=./
	RM=rm -f
endif
#######������WINDOWS��һ���ĵط�������
n=dialog.c
SRCEXT:=$(suffix $(n))
CC=gcc
CXX=g++
ifeq ($(SRCEXT),$(findstring $(SRCEXT),.c .i))
	C=CC
	FLAGS=CFLAGS
else
	C=CXX
	FLAGS=CXXFLAGS
endif
#######���C������c����c++������

GTK_VERSION=gtk+-3.0
GTK_CFLAGS=`pkg-config --cflags $(GTK_VERSION)`
GTK_LIBS=`pkg-config --libs $(GTK_VERSION)`
INCLUDES=-I.
CFLAGS=-Wall -std=c99 -O2 -g $(INCLUDES) $(GTK_CFLAGS)
CXXFLAGS=-Wall -std=c++11 -O2 -g $(INCLUDES) $(GTK_CFLAGS)
TARGET=$(notdir $(CURDIR)).$(TAREXT)
OBJS=$(patsubst %$(SRCEXT),%.o,$(n))
LIBS=$(GTK_LIBS)
LDFLAGS=$(LIBS) -L.




ECHO=echo $@:$? done...


.PHONY:all clean chname install


all:$(TARGET)
	$(RUN)$<
	@$(ECHO)


$(TARGET):$(OBJS)
	$($(C)) $^ $(LDFLAGS) -o $@


$(OBJS):%.o:%$(SRCEXT)
	$($(C)) -c $^ $($(FLAGS)) -o $@


clean:
	-@$(RM) $(OBJS) $(TARGET)
	@$(ECHO)

chname:
	sed -i "s/\<$(n)\>/$(N)/" makefile

install:$(TARGET)
	if [ ! -d exe ] ;then mkdir exe;fi
	for i in `ldd $(TARGET)|grep -vi system32|grep mingw64|awk '{print $$1}'` ;do cp -u /mingw64/bin/$$i exe ;done
	cp $(TARGET) exe
