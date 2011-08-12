/*
    Copyright (c) 2011 Mahtab Ghamsari-Esfahani, Jamie Klassen, Alastair Porter, Andrew Hankinson

    Permission is hereby granted, free of charge, to any person obtaining
    a copy of this software and associated documentation files (the
    "Software"), to deal in the Software without restriction, including
    without limitation the rights to use, copy, modify, merge, publish,
    distribute, sublicense, and/or sell copies of the Software, and to
    permit persons to whom the Software is furnished to do so, subject to
    the following conditions:

    The above copyright notice and this permission notice shall be
    included in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
    LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
    OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
    WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/


#ifndef MEIDOCUMENT_H_
#define MEIDOCUMENT_H_

#include <string>
#include <vector>
#include <map>
#include "meielement.h"

#include <libxml/xmlreader.h>

#define MEI_VERSION "2011-05"
#define MEI_NS "http://www.music-encoding.org/ns/mei"
#define MEI_PREFIX "mei"
#define ENCODING "UTF-8"

using std::string;
using std::map;

/** \brief The entity which will contains all the elements and attributes 
 *         storing a musical piece in the MEI schema. 
 * 
 * An MeiDocument is the first entity created or used when reading and writing MEI files. 
 * All musical information for a piece is stored as a tree of MeiElements within the MeiDocument. 
 * The document itself contains a name and an encoding, both of which are needed to identify it. 
 * MeiDocuments can be written to and Read from XML.
 */

class MeiDocument
	{
	public:
        /** \brief The MeiDocument Constructor, requires the document name and encoding
         */
		MeiDocument(string docname, string encoding);
		
        /** \brief Get the name of the document
         *  
         *  Each document is initially creating with a name and encoding thus a document 
         *  name must exist if a valid Mei document exists
         *  \return The document name
         */
		string getDocName();
        
        /** \brief Set/change the name of the Mei document */
        void setDocName(string docname);
        
        /** \brief Get the string indicating the Mei document encoding*/
		string getEncoding();
		
        /** \brief Set/change the encoding of the Mei document*/
		void setEncoding(string encoding);
        
        /** \brief Find the root element of the tree structure in the Mei document*/
		MeiElement* getRootElement();
		
        /** \brief Make an Mei element the Root element of a document*/
        void setRootElement(MeiElement* root);
        
        /** \return The Mei element with the given id. */
        MeiElement* getElementById(string id);
		
	private:
        map<string,MeiElement*> *getMap();
        void FillMap(MeiElement* element);
        
		string docname;
		string encoding;
		MeiElement* root;
        map<string,MeiElement*> *idmap;
	};

#endif // MEIDOCUMENT_H_
