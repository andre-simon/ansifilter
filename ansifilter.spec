#%define prefix  /usr

# Release number can be specified with rpmbuild --define 'rel SOMETHING' ...
# If no such --define is used, the release number is 1.
#
# Source archive's extension can be specified with --define 'srcext .foo'
# where .foo is the source archive's actual extension.
# To compile an RPM from a .bz2 source archive, give the command
#   rpmbuild -tb --define 'srcext bz2' @PACKAGE@-@VERSION@.tar.bz2
#


%if %{?srcext:0}%{!?srcext:1}
%define srcext bz2
%endif

Name:    ansifilter
Summary: ANSI terminal escape code converter
Version: 1.7
Release: 1
Group:   Development/Tools
License: GPLv3
Vendor:  Andre Simon <andre.simon1@gmx.de>
URL:     http://www.andre-simon.de/

Source0:   http://www.andre-simon.de/zip/%{name}-%{version}.tar.%{srcext}
Buildroot: %{_tmppath}/%{name}-%{version}.%{release}-root

%description
Ansifilter handles text files containing ANSI terminal escape codes.
The command sequences may be stripped or be interpreted to generate formatted 
output (HTML, RTF, TeX, LaTeX, BBCode).

%prep
%setup -q -n ansifilter-%{version}

%build
make

%install
if [ -d $RPM_BUILD_ROOT ]; then rm -r $RPM_BUILD_ROOT; fi
install -d $RPM_BUILD_ROOT%
install -d $RPM_BUILD_ROOT%{_mandir}/man1
install -d $RPM_BUILD_ROOT%{_defaultdocdir}/ansifilter/

install -m644 ./man/ansifilter.1.gz $RPM_BUILD_ROOT%{_mandir}/man1/ansifilter.1.gz
install -m644 ChangeLog  COPYING INSTALL README $RPM_BUILD_ROOT%{_defaultdocdir}/ansifilter/
mkdir -p $RPM_BUILD_ROOT%{_bindir}
install -m755 ./src/ansifilter  $RPM_BUILD_ROOT%{_bindir}

%clean
rm -fr %{buildroot}

%files
%defattr(-,root,root,-)

%{_defaultdocdir}/ansifilter
%{_mandir}/man1/ansifilter.1.gz
%{_bindir}/ansifilter

%changelog 

* Mon Nov 03 2008 Andre Simon <as@andre-simon.de> 1.2-1
— initial spec file

