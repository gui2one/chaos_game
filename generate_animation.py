import os
import random, math, sys

if sys.argv.__len__() > 1 :
    animation_name = sys.argv[1]
    
    base_name = os.path.basename(animation_name)
    if os.path.isdir(animation_name):
        print("is a directory")
    else:
        
        print("is NOT a directory")
        print("base name --> ", base_name)
        os.makedirs(animation_name)
    
else:
    print("I need a name for the animation")
    sys.exit(0)

def fit01( _val, _min , _max):
    return ((_max - _min)*_val) + _min

# print(fit01(0.5,10,30))

number_of_frames = 50.0
for i in range (int(number_of_frames)):
    radius = 2.0
    npt = 6    
    amount = fit01(i/number_of_frames,0.6,0.45)
    ignore = 1
    maxIter = 1000000
    alpha = 0.004

    path = "%s/%s_%s.bmp"%(animation_name, base_name  ,i+1)
    
    os.system("./build/chaos_game -npt %s -am %s -r %s -ig %i -maxiterations %i -a %s -o %s"%(npt, amount , radius, ignore, maxIter, alpha, path))
