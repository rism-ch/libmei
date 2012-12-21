LibMEI
------

LibMEI is a C++ library for reading and writing [MEI](http://music-encoding.org) files

It is developed by the [Distributed Digital Music Archives and Libraries Lab](http://ddmal.music.mcgill.ca/)
at the Schulich School of Music at McGill University, Montréal, Canada

License
-------
LibMEI is released under the MIT license.

Compilation & Usage
-------------------

We provide an XCode project for OSX and a cmake script for Linux.

To build on Linux, simply

    mkdir build; cd build
    cmake ..
    make
    sudo make install

To build on Windows:

1. If needed Install Visual C++ Studio Express and CMake for Windows

2. Get the libxml2 libraries (along with iconv) (currently found here: http://www.zlatkovic.com/libxml.en.html)

    i. Optionally, get gTest Libraries for testing the compilation of libmei

3. Open CMake, select libmei source code as source and choose desired directory to build VC++ project files
4. Press configure and check advanced:

    i. Change UUID_INCLUDE_DIR to the directory where UUID and RPC are located (Most likely something similar to C:/Program Files (x86)/Microsoft SDKs/Windows/v7.0A/Include)

    ii. Change UUID_LIBRARY to the UUID.lib (found in the lib folder of the same directory above)

    iii. Change the LIBXML_INCLUDE_DIR to the include folder of wherever you downloaded Libxml2 to

    iv. Change the LIBXML_LIBRARY to the libxml2.lib location (in the lib folder of wherever you downloaded libxml2)
    
    v. Change ICONV_INCLUDE_DIR to wherever ICONV/include was downloaded to
    
    vi. Change ICONV_LIBRARY to wherever ICONV/lib/iconv.lib was downloaded to
    
    v. Change GTEST Library and Include directory links to wherever the Gtests are built if you wish to include them.
5. Generate the VC++ project.
6. In the chosen build directory open libmei.sln
7. For the generate mei project
    i. Right click -> Properties
        a. In additional include libraries link to to the directory where UUID and RPC are located (Most likely something similar to C:/Program Files (x86)/Microsoft SDKs/Windows/v7.0A/Include)
        b. In Linker->Console: In the input box write: Rpcrt4.lib and apply
8. Repeat this for GTests which you wish to run (also you will need to add the Gtest include folder to Additional Include Dependencies)
9. Build the project as a release 

NOTE: THIS ONLY CURRENTLY WORKS WITH THE CORE LIBMEI ON WINDOWS, TO BUILD WITHOUT ERRORS MUST EXCLUDE THE MODULES FOLDER AND COMMENT OUT REFERENCES TO IT BEFORE GENERATING WITH CMAKE

To use libmei, include

    #include <mei/mei.h>

We provide two sample applications to demonstrate use. ```util/readmei.cpp``` is a trivial
example of reading and writing MEI, and making a change to the document structure.
```util/mxmltomei``` contains a tool to convert between MusicXML and MEI. This tool is
still in active development.

More detailed information about compilation and use is available at the
libmei wiki: https://github.com/DDMAL/libmei/wiki

Python
-------
LibMEI ships with Python bindings using the Boost-Python framework. More information about installing and using
these bindings can be found in [Installing the Python bindings](https://github.com/DDMAL/libmei/wiki/Installing-the-Python-bindings)

Customization
-------------
One of the most useful features of the MEI specification is the ability to generate custom schemas (in RelaxNG, DTD or W3C Schema)
containing only the music notation features that you require. For example, there is no need to validate documents written in mensural
notation against the Common Music Notation features of MEI. Also, MEI allows you to define new customizations for musical features that
may not be covered under the core specification. These are features inherited from the TEI project, and you can read more about
them on the [ODD Overview Page](http://www.tei-c.org/Guidelines/Customization/odds.xml) or in [our paper about MEI and LibMEI](http://ismir2011.ismir.net/papers/OS3-1.pdf).

LibMEI ships with tools that allow you to easily work with these customizations to limit or expand the functionality. In the `tools` directory
we include a Python script, `parseschema2.py` that will generate custom code for you in either C++ or Python. (Other languages may be added as well, if requested).

You can read more about customization and custom compiliation on our [wiki pages](https://github.com/DDMAL/libmei/wiki/Automatic-Code-Generation).

Authors
-------

* Andrew Hankinson
* Alastair Porter
* Greg Burlet
* Jamie Klassen
* Mahtab Ghamsari

Development of LibMEI was made possible with funding from the
Social Sciences and Humanities Research Council of Canada

Contributions
-------------
We welcome bug reports, feature requests, and patches to the libmei project page:
https://github.com/DDMAL/libmei
