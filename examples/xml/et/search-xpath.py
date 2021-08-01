#!/usr/bin/python3
# vim: set sts=4 expandtab:
#
import xml.etree.ElementTree as ET
import re

def search_retext(element, text, xpath=''):
    retext = re.compile(text)
    if xpath == '':
        xpath = element.tag
    subelements = element.findall('*')
    tagcount = {}
    if subelements != []:
        for s in subelements:
            if s.tag in tagcount:
                tagcount[s.tag] += 1
            else:
                tagcount[s.tag] = 1
            subxpath = xpath + '/' + s.tag + '[' + str(tagcount[s.tag]) + ']'
            if not (s.text is None):
                if retext.search(s.text.strip()):
                    print("=> %s" % subxpath)
                    print("with '%s': '%s'" % (text, s.text.strip()))
            search_retext(s, text,  subxpath)
    return
if __name__ == '__main__':
    tree = ET.parse('jouyou.xml')
    root = tree.getroot()
    print("search_retext(root, '^一覧')")
    search_retext(root, '^一覧')
    print("search_retext(root, '^本表')")
    search_retext(root, '^本表')
    print("search_retext(root, '^亜')")
    search_retext(root, '^亜')
    print("search_retext(root, '^葛')")
    search_retext(root, '^葛')
