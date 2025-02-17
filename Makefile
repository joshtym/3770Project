#############################################################################
# Makefile for building: bin/3770Project
# Generated by qmake (2.01a) (Qt 4.6.2) on: Sun Apr 3 22:59:24 2016
# Project:  3770Project.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -unix -o Makefile 3770Project.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB
CFLAGS        = -m64 -pipe -O2 -g -pipe -Wall -Wp,-D_FORTIFY_SOURCE=2 -fstack-protector --param=ssp-buffer-size=4 -m64 -mtune=generic -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -O2 -g -pipe -Wall -Wp,-D_FORTIFY_SOURCE=2 -fstack-protector --param=ssp-buffer-size=4 -m64 -mtune=generic -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/lib64/qt4/mkspecs/linux-g++-64 -I. -I/usr/include/QtCore -I/usr/include/QtGui -I/usr/include -I. -Iinclude -Imoc
LINK          = g++
LFLAGS        = -m64 -Wl,-O1
LIBS          = $(SUBLIBS)   -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake-qt4
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = 
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = obj/

####### Files

SOURCES       = src/PartPickerWindow.cc \
		src/main.cc \
		src/ProcessorWindow.cc \
		src/MotherboardWindow.cc \
		src/SpecificationWindow.cc \
		src/RamWindow.cc \
		src/HardDriveWindow.cc \
		src/InfoWindow.cc \
		src/ConfirmationWindow.cc \
		src/PartPageInterface.cc moc/moc_PartPickerWindow.cpp \
		moc/moc_SpecificationWindow.cpp \
		moc/moc_InfoWindow.cpp \
		moc/moc_ConfirmationWindow.cpp \
		moc/moc_PartPageInterface.cpp
OBJECTS       = obj/PartPickerWindow.o \
		obj/main.o \
		obj/ProcessorWindow.o \
		obj/MotherboardWindow.o \
		obj/SpecificationWindow.o \
		obj/RamWindow.o \
		obj/HardDriveWindow.o \
		obj/InfoWindow.o \
		obj/ConfirmationWindow.o \
		obj/PartPageInterface.o \
		obj/moc_PartPickerWindow.o \
		obj/moc_SpecificationWindow.o \
		obj/moc_InfoWindow.o \
		obj/moc_ConfirmationWindow.o \
		obj/moc_PartPageInterface.o
DIST          = /usr/lib64/qt4/mkspecs/common/g++-multilib.conf \
		/usr/lib64/qt4/mkspecs/common/unix.conf \
		/usr/lib64/qt4/mkspecs/common/linux.conf \
		/usr/lib64/qt4/mkspecs/qconfig.pri \
		/usr/lib64/qt4/mkspecs/features/qt_functions.prf \
		/usr/lib64/qt4/mkspecs/features/qt_config.prf \
		/usr/lib64/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/lib64/qt4/mkspecs/features/default_pre.prf \
		/usr/lib64/qt4/mkspecs/features/release.prf \
		/usr/lib64/qt4/mkspecs/features/default_post.prf \
		/usr/lib64/qt4/mkspecs/features/warn_on.prf \
		/usr/lib64/qt4/mkspecs/features/qt.prf \
		/usr/lib64/qt4/mkspecs/features/unix/thread.prf \
		/usr/lib64/qt4/mkspecs/features/moc.prf \
		/usr/lib64/qt4/mkspecs/features/resources.prf \
		/usr/lib64/qt4/mkspecs/features/uic.prf \
		/usr/lib64/qt4/mkspecs/features/yacc.prf \
		/usr/lib64/qt4/mkspecs/features/lex.prf \
		/usr/lib64/qt4/mkspecs/features/include_source_dir.prf \
		3770Project.pro
QMAKE_TARGET  = 3770Project
DESTDIR       = bin/
TARGET        = bin/3770Project

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	@$(CHK_DIR_EXISTS) bin/ || $(MKDIR) bin/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: 3770Project.pro  /usr/lib64/qt4/mkspecs/linux-g++-64/qmake.conf /usr/lib64/qt4/mkspecs/common/g++-multilib.conf \
		/usr/lib64/qt4/mkspecs/common/unix.conf \
		/usr/lib64/qt4/mkspecs/common/linux.conf \
		/usr/lib64/qt4/mkspecs/qconfig.pri \
		/usr/lib64/qt4/mkspecs/features/qt_functions.prf \
		/usr/lib64/qt4/mkspecs/features/qt_config.prf \
		/usr/lib64/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/lib64/qt4/mkspecs/features/default_pre.prf \
		/usr/lib64/qt4/mkspecs/features/release.prf \
		/usr/lib64/qt4/mkspecs/features/default_post.prf \
		/usr/lib64/qt4/mkspecs/features/warn_on.prf \
		/usr/lib64/qt4/mkspecs/features/qt.prf \
		/usr/lib64/qt4/mkspecs/features/unix/thread.prf \
		/usr/lib64/qt4/mkspecs/features/moc.prf \
		/usr/lib64/qt4/mkspecs/features/resources.prf \
		/usr/lib64/qt4/mkspecs/features/uic.prf \
		/usr/lib64/qt4/mkspecs/features/yacc.prf \
		/usr/lib64/qt4/mkspecs/features/lex.prf \
		/usr/lib64/qt4/mkspecs/features/include_source_dir.prf
	$(QMAKE) -unix -o Makefile 3770Project.pro
/usr/lib64/qt4/mkspecs/common/g++-multilib.conf:
/usr/lib64/qt4/mkspecs/common/unix.conf:
/usr/lib64/qt4/mkspecs/common/linux.conf:
/usr/lib64/qt4/mkspecs/qconfig.pri:
/usr/lib64/qt4/mkspecs/features/qt_functions.prf:
/usr/lib64/qt4/mkspecs/features/qt_config.prf:
/usr/lib64/qt4/mkspecs/features/exclusive_builds.prf:
/usr/lib64/qt4/mkspecs/features/default_pre.prf:
/usr/lib64/qt4/mkspecs/features/release.prf:
/usr/lib64/qt4/mkspecs/features/default_post.prf:
/usr/lib64/qt4/mkspecs/features/warn_on.prf:
/usr/lib64/qt4/mkspecs/features/qt.prf:
/usr/lib64/qt4/mkspecs/features/unix/thread.prf:
/usr/lib64/qt4/mkspecs/features/moc.prf:
/usr/lib64/qt4/mkspecs/features/resources.prf:
/usr/lib64/qt4/mkspecs/features/uic.prf:
/usr/lib64/qt4/mkspecs/features/yacc.prf:
/usr/lib64/qt4/mkspecs/features/lex.prf:
/usr/lib64/qt4/mkspecs/features/include_source_dir.prf:
qmake:  FORCE
	@$(QMAKE) -unix -o Makefile 3770Project.pro

dist: 
	@$(CHK_DIR_EXISTS) obj/3770Project1.0.0 || $(MKDIR) obj/3770Project1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) obj/3770Project1.0.0/ && $(COPY_FILE) --parents include/PartPickerWindow.h include/ProcessorWindow.h include/MotherboardWindow.h include/SpecificationWindow.h include/RamWindow.h include/HardDriveWindow.h include/InfoWindow.h include/ConfirmationWindow.h include/PartPageInterface.h obj/3770Project1.0.0/ && $(COPY_FILE) --parents src/PartPickerWindow.cc src/main.cc src/ProcessorWindow.cc src/MotherboardWindow.cc src/SpecificationWindow.cc src/RamWindow.cc src/HardDriveWindow.cc src/InfoWindow.cc src/ConfirmationWindow.cc src/PartPageInterface.cc obj/3770Project1.0.0/ && (cd `dirname obj/3770Project1.0.0` && $(TAR) 3770Project1.0.0.tar 3770Project1.0.0 && $(COMPRESS) 3770Project1.0.0.tar) && $(MOVE) `dirname obj/3770Project1.0.0`/3770Project1.0.0.tar.gz . && $(DEL_FILE) -r obj/3770Project1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc/moc_PartPickerWindow.cpp moc/moc_SpecificationWindow.cpp moc/moc_InfoWindow.cpp moc/moc_ConfirmationWindow.cpp moc/moc_PartPageInterface.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc/moc_PartPickerWindow.cpp moc/moc_SpecificationWindow.cpp moc/moc_InfoWindow.cpp moc/moc_ConfirmationWindow.cpp moc/moc_PartPageInterface.cpp
moc/moc_PartPickerWindow.cpp: include/InfoWindow.h \
		include/SpecificationWindow.h \
		include/ConfirmationWindow.h \
		include/PartPageInterface.h \
		include/PartPickerWindow.h
	/usr/lib64/qt4/bin/moc $(DEFINES) $(INCPATH) include/PartPickerWindow.h -o moc/moc_PartPickerWindow.cpp

moc/moc_SpecificationWindow.cpp: include/SpecificationWindow.h
	/usr/lib64/qt4/bin/moc $(DEFINES) $(INCPATH) include/SpecificationWindow.h -o moc/moc_SpecificationWindow.cpp

moc/moc_InfoWindow.cpp: include/SpecificationWindow.h \
		include/InfoWindow.h
	/usr/lib64/qt4/bin/moc $(DEFINES) $(INCPATH) include/InfoWindow.h -o moc/moc_InfoWindow.cpp

moc/moc_ConfirmationWindow.cpp: include/ConfirmationWindow.h
	/usr/lib64/qt4/bin/moc $(DEFINES) $(INCPATH) include/ConfirmationWindow.h -o moc/moc_ConfirmationWindow.cpp

moc/moc_PartPageInterface.cpp: include/SpecificationWindow.h \
		include/PartPageInterface.h
	/usr/lib64/qt4/bin/moc $(DEFINES) $(INCPATH) include/PartPageInterface.h -o moc/moc_PartPageInterface.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

obj/PartPickerWindow.o: src/PartPickerWindow.cc include/PartPickerWindow.h \
		include/InfoWindow.h \
		include/SpecificationWindow.h \
		include/ConfirmationWindow.h \
		include/PartPageInterface.h \
		include/ProcessorWindow.h \
		include/MotherboardWindow.h \
		include/RamWindow.h \
		include/HardDriveWindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/PartPickerWindow.o src/PartPickerWindow.cc

obj/main.o: src/main.cc include/PartPickerWindow.h \
		include/InfoWindow.h \
		include/SpecificationWindow.h \
		include/ConfirmationWindow.h \
		include/PartPageInterface.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/main.o src/main.cc

obj/ProcessorWindow.o: src/ProcessorWindow.cc include/ProcessorWindow.h \
		include/PartPageInterface.h \
		include/SpecificationWindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/ProcessorWindow.o src/ProcessorWindow.cc

obj/MotherboardWindow.o: src/MotherboardWindow.cc include/MotherboardWindow.h \
		include/PartPageInterface.h \
		include/SpecificationWindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/MotherboardWindow.o src/MotherboardWindow.cc

obj/SpecificationWindow.o: src/SpecificationWindow.cc include/SpecificationWindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/SpecificationWindow.o src/SpecificationWindow.cc

obj/RamWindow.o: src/RamWindow.cc include/RamWindow.h \
		include/PartPageInterface.h \
		include/SpecificationWindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/RamWindow.o src/RamWindow.cc

obj/HardDriveWindow.o: src/HardDriveWindow.cc include/HardDriveWindow.h \
		include/PartPageInterface.h \
		include/SpecificationWindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/HardDriveWindow.o src/HardDriveWindow.cc

obj/InfoWindow.o: src/InfoWindow.cc include/InfoWindow.h \
		include/SpecificationWindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/InfoWindow.o src/InfoWindow.cc

obj/ConfirmationWindow.o: src/ConfirmationWindow.cc include/ConfirmationWindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/ConfirmationWindow.o src/ConfirmationWindow.cc

obj/PartPageInterface.o: src/PartPageInterface.cc include/PartPageInterface.h \
		include/SpecificationWindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/PartPageInterface.o src/PartPageInterface.cc

obj/moc_PartPickerWindow.o: moc/moc_PartPickerWindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/moc_PartPickerWindow.o moc/moc_PartPickerWindow.cpp

obj/moc_SpecificationWindow.o: moc/moc_SpecificationWindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/moc_SpecificationWindow.o moc/moc_SpecificationWindow.cpp

obj/moc_InfoWindow.o: moc/moc_InfoWindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/moc_InfoWindow.o moc/moc_InfoWindow.cpp

obj/moc_ConfirmationWindow.o: moc/moc_ConfirmationWindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/moc_ConfirmationWindow.o moc/moc_ConfirmationWindow.cpp

obj/moc_PartPageInterface.o: moc/moc_PartPageInterface.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/moc_PartPageInterface.o moc/moc_PartPageInterface.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

