import os
import random, math

def fit01( _val, _min , _max):
    return ((_max - _min)*_val) + _min

# print(fit01(0.5,10,30))
for i in range (30):
    rand1 = random.random()
    radius = fit01(rand1,0.6,2.2)
    radius = 1.0

    rand2 = random.random()
    npt = math.floor(fit01(rand2,4,9))
    # npt = 5
    
    rand3 = random.random()
    amount = fit01(rand3,0.5,0.6)
    # amount= 0.5
    rand4 = random.random()

    ignore = math.floor(fit01(rand4,0,3 ))
    path = "output/output_%s.bmp"%(i+1)
    
    print("ignore", ignore)
    os.system("./build/chaos_game -npt %s -am %s -r %s -ig %i -o %s"%(npt, amount , radius, ignore, path))
