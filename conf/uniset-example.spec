%def_disable doc
%def_enable omninames

%define prj_group uniset-example

Name: uniset-example
Version: 0.1
Release: eter1

Summary: UNISET-EXAMPLE

License: GPL
Group: Development/C++
URL: http://etersoft.ru

Source: %name-%version.tar

# Due uniwidgets not supports x86_64 yet
ExclusiveArch: %ix86

# Automatically added by buildreq on Thu Feb 19 2009
BuildRequires: glibc-devel-static libuniset2-extensions-devel libuniset2-utils

BuildRequires: libuniset2-devel >= 2.2-alt28

Requires: libuniset2 >= 2.2-alt28
Requires: libuniset2-extensions
Requires: libuniset2-utils
Requires: libomniORB-names
#Requires: rdate

Summary: Common package for uniset-example
Group: Development/Other

AutoReq: no
%define findreq_default_method none

%description
This is special example project

%package doc
Summary: Documentation for uniset-example
Group: Development/Other
Requires: %name = %version-%release
AutoReq: no
%description doc
Documentation for uniset-example project

%prep
%setup

%build
%autoreconf
%configure %{subst_enable docs} %{subst_enable omninames} --localstatedir=%{_var}
NPROCS=1 %make_build
#%make

%install
%makeinstall_std
mkdir -p -m755 %buildroot%_logdir/%name
mkdir -p -m755 %buildroot%_runtimedir/%name
mkdir -p -m755 %buildroot%_lockdir/%name
mkdir -p -m755 %buildroot%_runtimedir/%name/omniORB

mkdir -p -m755 %buildroot%_initdir
mv %buildroot%_bindir/%{name} %buildroot%_initdir/%{name}

%files -n %name
%config %_initdir/%{name}
#%config(noreplace) %_sysconfdir/%name/configure.xml
#%_sysconfdir/%name/configure.xml

%_bindir/smemory2*
%_bindir/ctl-admin*
%_bindir/ctl-functions*
%_bindir/ctl-omninames*
%_bindir/ctl-script*
%_bindir/ctl-syslog*
%_bindir/ctl-system*
%_bindir/ctl-update*
%_bindir/ctl-install*
%_bindir/ctl-smview*
%_bindir/ctl-smonit*

%dir %_datadir/%name/

%attr(0775,root,%prj_group) %dir %_logdir/%name
%attr(0775,root,%prj_group) %dir %_runtimedir/%name
%attr(0775,root,%prj_group) %dir %_lockdir/%name
%attr(0775,root,%prj_group) %dir %_runtimedir/%name/omniORB

%_bindir/ctl-all*
%_bindir/ctl-monit-func-%name.sh
%_bindir/ctl-synctime.sh
%_bindir/ctl-sethost.sh

%if_enabled doc
%files doc
%_docdir/%name-%version/
%endif
