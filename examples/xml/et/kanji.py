#!/usr/bin/python3
# vim: set sts=4 expandtab:

import xml.etree.ElementTree as ET

def search_kanji(element):
    kanji = [] 
    for row in element.findall('body[1]/div[3]/div[3]/div[4]/table[2]/tr'):
        # processing table for each row (expandable!)
        k = row.find('td[2]/a')
        if k is None:
            continue
        kanji.append(k.text)
    return kanji

if __name__ == '__main__':
    element = ET.parse('jouyou.xml')
    root = element.getroot()
    print(search_kanji(root))
