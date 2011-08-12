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


#include "meidocument.h"
#include "meielement.h"

using std::map;

MeiDocument::MeiDocument(string docname, string encoding) {
	this->docname = docname;
	this->encoding = encoding;
    this->root = NULL;
}

string MeiDocument::getDocName() {
	return docname;
}

void MeiDocument::setDocName(string docname) {
    this->docname = docname;
}

string MeiDocument::getEncoding() {
	return encoding;
}

void MeiDocument::setEncoding(string encoding) {
	this->encoding = encoding;
}

MeiElement* MeiDocument::getRootElement() {
	return root;
}

void MeiDocument::setRootElement(MeiElement* root) {
    if (root->getNs().href == "") {
        MeiNs ns = root->getNs();
        ns.href = MEI_NS;
        root->setNs(ns);
    }
    root->AttSetter("meiversion",MEI_VERSION);
    this->root = root;
}

MeiElement* MeiDocument::getElementById(string id) {
    map<string,MeiElement*>::iterator it = getMap()->find(id);
    if (it != getMap()->end()) {
        return it->second;
    }
    return NULL;
} 

map<string,MeiElement*> *MeiDocument::getMap() {
    if (!idmap) {
        idmap = new map<string,MeiElement*>;
        FillMap(root);
    }
    return idmap;
}

void MeiDocument::FillMap(MeiElement* element) {
    MeiAttribute *idattr = element->getAttribute("id");
    if (idattr) {
        getMap()->insert(std::make_pair(idattr->getValue(),element));
    }
    for (vector<MeiElement*>::iterator i = element->getChildren().begin(); i != element->getChildren().end(); ++i) {
        FillMap(*i);
    }
}