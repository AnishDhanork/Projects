import RPi.GPIO as GPIO
from time import sleep
import time
import schedule
import pigpio

green = 17
blue = 24
red = 21

GPIO.setmode(GPIO.BCM)

GPIO.setup(22,GPIO.OUT)
pi = pigpio.pi()


#assuming 20 grams of food is being dropped on every rotation

print("Choose an operation:")
print("1. Run the program now.\n2. Schedule the program for a later time.")
c=int(input())

def inputfood():
    print("Enter the amount of food to be deliverd per serving(in grams):")
    global food
    food=int(input())
    print(food,"grams of food needs to be dispensed. Please confirm: Y or N")
    choice=str(input())

    while(choice!="Y"):
        print("Enter the amount of food to be deliverd per serving(in grams):")
        food=int(input())
        print(food,"grams of food needs to be dispensed. Please confirm: Y or N")
        choice=str(input())
        
    print("Confirmed.\n") 

def now():
    green = 17
    blue = 24
    red = 21

    GPIO.setmode(GPIO.BCM)

    GPIO.setup(22,GPIO.OUT)
    pi = pigpio.pi()

    servo=GPIO.PWM(22,100)

    servo.start(0)

    duty=(268/18)+2
    
    pi.set_PWM_dutycycle(blue, 255)
    inputfood()
    pi.set_PWM_dutycycle(blue, 0)
    rotations=(food/20)
    rotations=round(rotations)
    print("Number of rotations to be made=",rotations)

    i=0
    while(i<rotations):
        GPIO.output(22, True)
        pi.set_PWM_dutycycle(red, 255)
        servo.ChangeDutyCycle(duty)
        sleep(2.2) #Turns out the duty cycle can be anything cause the sleep function can be used to control how long the arm rotates
        servo.ChangeDutyCycle(0)
        pi.set_PWM_dutycycle(red, 0)
        print("Rotations=",i+1)
        sleep(1)
        i=i+1

    pi.set_PWM_dutycycle(green, 255)
    print("\n",food,"grams of food has been dispensed.")
    sleep(5)
    pi.set_PWM_dutycycle(green, 0)
    GPIO.cleanup()
    pi.stop()
    return schedule.CancelJob


def later():
    green = 17
    blue = 24
    red = 21

    GPIO.setmode(GPIO.BCM)

    GPIO.setup(22,GPIO.OUT)
    pi = pigpio.pi()

    servo=GPIO.PWM(22,100)

    servo.start(0)

    duty=(268/18)+2
    
    print("Dispensing food now.")
    
    rotations=(food/20)
    rotations=round(rotations)
    print("Number of rotations to be made=",rotations)

    i=0
    while(i<rotations):
        GPIO.output(22, True)
        pi.set_PWM_dutycycle(red, 255)
        servo.ChangeDutyCycle(duty)
        sleep(2.2) #Turns out the duty cycle can be anything cause the sleep function can be used to control how long the arm rotates
        servo.ChangeDutyCycle(0)
        pi.set_PWM_dutycycle(red, 0)
        print("Rotations=",i+1)
        sleep(1)
        i=i+1

    pi.set_PWM_dutycycle(green, 255)
    print("\n",food,"grams of food has been dispensed.")
    sleep(5)
    pi.set_PWM_dutycycle(green, 0)
    GPIO.cleanup()
    pi.stop()
    return schedule.CancelJob

if (c==1):
    now()
    
elif (c==2):
    pi.set_PWM_dutycycle(blue, 255)
    print("When do you want to run the program:")
    print("1. In a few seconds.\n2. In a few minutes.\n3. In a few hours.\n4. Manually set the time.")
    s=int(input())
    
    if (s==1):
        print("In how many seconds should the program be run:")
        seconds=int(input())
        inputfood()
        pi.set_PWM_dutycycle(blue, 0)
            
        schedule.every(seconds).seconds.do(later)
        while True:
            schedule.run_pending()
            
    elif (s==2):
        print("In how many minutes should the program be run:")
        minutes=int(input())
        inputfood()
        pi.set_PWM_dutycycle(blue, 0)
            
        schedule.every(minutes).minutes.do(later)
        while True:
            schedule.run_pending()
            
    elif (s==3):
        print("In how many hours should the program be run:")
        hours=int(input())
        inputfood()
        pi.set_PWM_dutycycle(blue, 0)
            
        schedule.every(hours).hours.do(later)
        while True:
            schedule.run_pending()
            
    elif (s==4):
        print("Enter the exact time you want the program to run in HH:MM format(24H):")
        time=str(input())
        inputfood()
        pi.set_PWM_dutycycle(blue, 0)
            
        schedule.every().day.at(time).do(later)
        while True:
            schedule.run_pending()
            
    
