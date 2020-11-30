import turtle

bor = 200

player = turtle.Turtle()
player.shape("circle")
player.color("pink")
play = turtle.Screen()
player.left(90)


def up():
    player.forward(50)
    print("up")

def left():
    player.left(90)
    player.forward(50)
    player.right(90)
    print("left")

def down():
    player.backward(50)
    print("down")

def right():
    player.right(90)
    player.forward(50)
    player.left(90)
    print("right")


play.title("may game")
play.bgcolor("white")
play.setup(width=800,height=800)
play.listen()
play.onkey(up,"Up")
play.onkey(left,"Left")
play.onkey(down,"Down")
play.onkey(right,"Right")

if player.xcor() > bor or player.xcor() < -bor:
    player.backward(50)


if player.ycor() > bor or player.ycor() < -bor:
    player.backward(50)

play.mainloop()