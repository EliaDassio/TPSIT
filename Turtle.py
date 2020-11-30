side = int(input("input the number of sides of the shape (max 12): "))

while side < 3 or side > 12:
    side = int(input("please input a valid number ( 3 min, 12 max)"))

if side == 3:
    ang = 120
    le = 150
elif side == 4:
    ang = 90
    le = 100
elif side == 5:
    ang = 72
    le = 100
elif side == 6:
    ang = 60
    le = 100
elif side == 7:
    ang = 51.429
    le = 75
elif side == 8:
    ang = 45
    le = 75
elif side == 9:
    ang = 40
    le = 75
elif side == 10:
    ang = 36
    le = 50
elif side == 11:
    ang = 32.73
    le = 50
elif side == 12:
    ang = 30
    le = 50

from turtle import *
color('black', 'purple')
begin_fill()
while True:
    forward(le)
    left(ang)
    if abs(pos()) < 1:
        break
end_fill()
done()