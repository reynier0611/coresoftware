##############################################
# please add new classes in alphabetical order

AUTOMAKE_OPTIONS = foreign

# List of shared libraries to produce
lib_LTLIBRARIES = \
  libcalo_io.la \
  libcalo_util.la

libcalo_io_la_LDFLAGS = \
  -L$(libdir) \
  -L$(OFFLINE_MAIN)/lib

libcalo_io_la_LIBADD = \
  -lphool 

libcalo_util_la_LDFLAGS = \
  -L$(libdir) \
  -L$(OFFLINE_MAIN)/lib

libcalo_util_la_LIBADD = \
  -lCLHEP \
  libcalo_io.la

AM_CPPFLAGS = \
  -I$(includedir) \
  -I$(OFFLINE_MAIN)/include \
  -I$(ROOTSYS)/include

pkginclude_HEADERS = \
  RawClusterUtility.h \
  RawCluster.h \
  RawClusterv1.h \
  RawClusterDefs.h \
  RawClusterContainer.h \
  RawTower.h \
  RawTowerDefs.h \
  RawTowerv1.h \
  RawTowerContainer.h  \
  RawTowerDeadMap.h  \
  RawTowerDeadMapv1.h  \
  RawTowerGeom.h \
  RawTowerGeomv1.h \
  RawTowerGeomv2.h \
  RawTowerGeomv3.h \
  RawTowerGeomContainer.h \
  RawTowerGeomContainerv1.h \
  RawTowerGeomContainer_Cylinderv1.h

ROOTDICTS = \
  RawCluster_Dict.cc \
  RawClusterv1_Dict.cc \
  RawClusterContainer_Dict.cc \
  RawTower_Dict.cc \
  RawTowerv1_Dict.cc \
  RawTowerContainer_Dict.cc \
  RawTowerDeadMap_Dict.cc \
  RawTowerGeom_Dict.cc \
  RawTowerDeadMapv1_Dict.cc \
  RawTowerGeomv1_Dict.cc \
  RawTowerGeomv2_Dict.cc \
  RawTowerGeomv3_Dict.cc \
  RawTowerGeomContainer_Dict.cc \
  RawTowerGeomContainerv1_Dict.cc \
  RawTowerGeomContainer_Cylinderv1_Dict.cc
if MAKEROOT6
  pcmdir = $(libdir)
  nobase_dist_pcm_DATA = \
    RawCluster_Dict_rdict.pcm \
    RawClusterv1_Dict_rdict.pcm \
    RawClusterContainer_Dict_rdict.pcm \
    RawTower_Dict_rdict.pcm \
    RawTowerv1_Dict_rdict.pcm \
    RawTowerContainer_Dict_rdict.pcm \
    RawTowerDeadMap_Dict_rdict.pcm \
    RawTowerGeom_Dict_rdict.pcm \
    RawTowerDeadMapv1_Dict_rdict.pcm \
    RawTowerGeomv1_Dict_rdict.pcm \
    RawTowerGeomv2_Dict_rdict.pcm \
    RawTowerGeomv3_Dict_rdict.pcm \
    RawTowerGeomContainer_Dict_rdict.pcm \
    RawTowerGeomContainerv1_Dict_rdict.pcm \
    RawTowerGeomContainer_Cylinderv1_Dict_rdict.pcm
else
  ROOT5_IO_DICTS = \
    RawClusterDefs_Dict.cc \
    RawTowerDefs_Dict.cc 

  ROOT5_DICTS = \
    RawClusterUtility_Dict.cc
endif

libcalo_io_la_SOURCES = \
  $(ROOTDICTS) \
  $(ROOT5_IO_DICTS) \
  RawCluster.cc \
  RawClusterv1.cc \
  RawClusterContainer.cc \
  RawTowerv1.cc \
  RawTowerContainer.cc \
  RawTowerDeadMap.cc \
  RawTowerDeadMapv1.cc \
  RawTowerGeom.cc \
  RawTowerGeomv1.cc \
  RawTowerGeomv2.cc \
  RawTowerGeomv3.cc \
  RawTowerGeomContainer.cc \
  RawTowerGeomContainerv1.cc \
  RawTowerGeomContainer_Cylinderv1.cc

libcalo_util_la_SOURCES = \
  $(ROOT5_DICTS)


# Rule for generating table CINT dictionaries.
%_Dict.cc: %.h %LinkDef.h
	rootcint -f $@ @CINTDEFS@ -c $(DEFAULT_INCLUDES) $(AM_CPPFLAGS) $^

#just to get the dependency
%_Dict_rdict.pcm: %_Dict.cc ;

################################################
# linking tests

noinst_PROGRAMS = \
  testexternals_calo_util \
  testexternals_calo_io

BUILT_SOURCES = testexternals.cc

testexternals_calo_util_SOURCES = testexternals.cc
testexternals_calo_util_LDADD = libcalo_util.la

testexternals_calo_io_SOURCES = testexternals.cc
testexternals_calo_io_LDADD = libcalo_io.la

testexternals.cc:
	echo "//*** this is a generated file. Do not commit, do not edit" > $@
	echo "int main()" >> $@
	echo "{" >> $@
	echo "  return 0;" >> $@
	echo "}" >> $@

##############################################
# please add new classes in alphabetical order

clean-local:
	rm -f *Dict* $(BUILT_SOURCES) *.pcm
