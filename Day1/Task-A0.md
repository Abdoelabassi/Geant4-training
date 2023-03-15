Task A0
=======

Let's familiarise ourselves with the Geant4 virtual machine, and make some
customisations.

Familiarisation with Virtual Machine
------------------------------------
The default keyboard layout of the CENBG Geant4 virtual machine is the French 'AZERTY'.  To change this to the 'QWERTY' layout use the “-fr-“ menu near the top right corner.

First step in CentOS 8 virtual machine
--------------------------------------
Open a terminal using the "Applications" menu.  

Issue a few commands (type whatever is after the $ on the relevant lines )

```
$ cd 

$ pwd 
/home/local1

$ ls
Desktop/  Documents/  Downloads/  eclipse-workspace/  Templates/

$ whoami 
local1
```

If you are not familiar with the Unix shell, please brush up - at least a few key commands including 'ls', 'mkdir', 'cd' are critical for the course.  You  
can use the HSF ['Unix shell' training material](http://swcarpentry.github.io/shell-novice/)

```
$ whereis gedit

$ gedit
```
gedit and nedit are simple editors that exist on the system. 

Check for Geant4 installation
-----------------------------
Let's check that Geant4 is configured

```
$ cd
$ env | grep G4INS
G4INSTALL=/usr/local/geant4.10.07.p01

$ ls $G4INSTALL
```

Find the build tool 'cmake' - needed to build Geant4 applications
```
$ which cmake
/bin/cmake

$ whereis cmake
cmake: /usr/bin/cmake /usr/lib64/cmake /usr/share/cmake /usr/share/man/man1/cmake.1.gz
```

Add your favourite editor (optional)
------------------------------------
If case you prefer to add another editor of your choice, you can:

Note: the password for root is in the README
```
$ sudo
[Prompts for password here]

$ dnf install emacs
$ which emacs 
```

If you want a modern editor you can install 'atom' - we used the latest [instructions](https://flight-manual.atom.io/getting-started/sections/installing-atom/)
```
$ wget -qO - https://packagecloud.io/AtomEditor/atom/gpgkey | sudo apt-key add -
$ sudo sh -c 'echo "deb [arch=amd64] https://packagecloud.io/AtomEditor/atom/any/ any main" > /etc/apt/sources.list.d/atom.list'
$ sudo apt-get update
```
and then 
```
# Install Atom
$ sudo dnf install atom
```

Optional conveniences
----------------------

- Change the shell prompt - avoid the customisation of the Geant4-VM authors
```shell
unalias SetPrompt
unalias cd
set prompt="centos.%h%% "
```
you will get a new prompt
```
centos.23% date

centos.24%
```

- You could change the shell if you prefer bash, ksh, zsh
```shell
$ chsh -l

$ chsh -s /bin/bash

$ chsh -s /bin/ksh
```
BUT in that case you will need to configure your new shell to use the Geant4 installation on the system.

It is easier just to start your favourite shell in a terminal, after the Geant4 setup has already been run - keeping that configuration
```
/bin/bash

bash-4.4$ 

$ env | grep G4

G4UI_USE_TCSH=1
G4INSTALL=/usr/local/geant4.10.07.p01
G4WORKDIR=/home/local1/geant4/work
```

Configuration of the Virtual Machine
------------------------------------
Default shell is “tcsh” and default language is “Fr” - French. 

There are security updates for CentOS 8 - if you have a fast connection we
suggest to install them - before or after today's course session. 
It took us 20 minutes on 100MBit Internet connection.
