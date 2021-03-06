#!/bin/bash -e

# Create a source rpm for Fedora/EPEL

cd "$(git rev-parse --show-toplevel)"
scripts/make-archive.sh
scripts/make-distrofiles.sh
mv knot-resolver_*.orig.tar.xz distro/rpm/
cd distro/rpm
rpkg srpm
mv *.src.rpm ../../
mv *.tar.xz ../../
