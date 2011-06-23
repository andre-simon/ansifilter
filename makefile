# Installation script for ansifilter.
# See INSTALL for details.

# Installation directories:

# Destination directory for installation (intended for packagers)
DESTDIR = 

# Root directory for final installation
PREFIX = /usr

# Location of the binary:
bin_dir = ${PREFIX}/bin/

# Location of the man page:
man_dir = ${PREFIX}/share/man/man1/

# Location of the documentation:
doc_dir = ${PREFIX}/share/doc/ansifilter/

# Commands:
QMAKE=qmake
#QMAKE=qmake-qt4

INSTALL_DATA=install -m644
INSTALL_PROGRAM=install -m755
MKDIR=mkdir -p -m 755
RMDIR=rm -r -f

all:
	${MAKE} -C ./src -f ./makefile 

all-gui gui:
	${QMAKE} -makefile -o src/qt-gui/Makefile src/qt-gui/ansifilter-gui.pro
	${MAKE} -C ./src/qt-gui -f ./Makefile

install:
	@echo "This script will install ansifilter in the following directories:"
	@echo "Documentation directory: ${DESTDIR}${doc_dir}"
	@echo "Manual directory:        ${DESTDIR}${man_dir}"
	@echo "Binary directory:        ${DESTDIR}${bin_dir}"
	@echo

	${MKDIR} ${DESTDIR}${doc_dir}
	${MKDIR} ${DESTDIR}${man_dir}
	${MKDIR} ${DESTDIR}${bin_dir}

	${INSTALL_DATA} ./man/ansifilter.1.gz ${DESTDIR}${man_dir}
	${INSTALL_DATA} ./README ${DESTDIR}${doc_dir}
	${INSTALL_DATA} ./ChangeLog ${DESTDIR}${doc_dir}
	${INSTALL_DATA} ./COPYING ${DESTDIR}${doc_dir}
	${INSTALL_DATA} ./INSTALL ${DESTDIR}${doc_dir}
	${INSTALL_PROGRAM} ./src/ansifilter ${DESTDIR}${bin_dir}

	@echo
	@echo "Done."
	@echo "Type ansifilter --help or man ansifilter for instructions."
	@echo "Do not hesitate to report problems. Unknown bugs are hard to fix."
	
install-gui:
	${INSTALL_PROGRAM} ./src/qt-gui/ansifilter-gui ${DESTDIR}${bin_dir}

uninstall:
	@echo "Removing ansifilter files from system..."
	${RMDIR} ${DESTDIR}${doc_dir}
	rm -f ${DESTDIR}${man_dir}ansifilter.1.gz
	rm -f ${DESTDIR}${bin_dir}ansifilter
	rm -f ${DESTDIR}${bin_dir}ansifilter-gui
	@echo "Done. Have a nice day!"

clean:
	$(MAKE) -C ./src -f ./makefile clean

apidocs:
	doxygen Doxyfile

help:
	@echo "This makefile offers the following options:"
	@echo
	@echo "(all)            Compile."
	@echo "all-gui          Compile Qt GUI (requires Qt 4.x)"
	@echo "install*         Copy all data files to ${data_dir}."
	@echo "clean            Remove object files and binary."
	@echo "uninstall*       Remove ansifilter files from system."
	@echo
	@echo "* Command needs root privileges."
	@echo "See src/makefile for compilation and linking options."

# Target needed for redhat 9.0 rpmbuild
install-strip:

.PHONY: clean all install apidocs help uninstall install-strip
