#!/usr/bin/python
# vi:se ts=4 sts=4 et:
class Fridge:
    def __init__(self, name):
        self.beer = 0
        print(name, "bought a new fridge.")
        self.name = name
    def report_beer(self):
        print(self.name, "has", self.beer, "can(s) of beer in stock.")
        return
    def stock_beer(self, cans):
        print(self.name, "stocks", cans, "can(s) of beer.")
        self.beer += cans
        return
    def consume_beer(self, cans):
        print(self.name, "tries to consume", cans, "can(s) of beer")
        if self.beer <= cans:
            print(("No more beer after drinking %i can(s) of beer!" % self.beer))
            self.beer = 0
        else:
            self.beer -= cans
        self.report_beer()
        return

class NormalFridge(Fridge):
    def __init__(self, name, min_beer):
        Fridge.__init__(self, name)
        print(name, "wishes to have", min_beer, "cans of beer")
        self.min_beer = min_beer
    def check_beer(self):
        if self.beer < self.min_beer:
            print(("%i extra can(s) of beer needed for good stocking." % 
                    (self.min_beer - self.beer)))
        return
    def consume_beer(self, cans):
        Fridge.consume_beer(self, cans)
        self.check_beer()
        return

def test(name = "Tom", minimum = 6):
    tom_fridge = NormalFridge(name, minimum)
    tom_fridge.stock_beer(12)
    tom_fridge.consume_beer(5)
    tom_fridge.consume_beer(5)
    tom_fridge.consume_beer(5)
    tom_fridge.stock_beer(8)
    tom_fridge.consume_beer(3)
    exit(0)

if __name__ == '__main__':
    test()
