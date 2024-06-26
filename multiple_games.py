# Made by a FIBER
# This program will play different matches with random seeds to allow
# you to test your program multiple times at once
#
# You may need to install ($pip3 install subprocess)
# To run it ($python3 multiple_games.py)

from subprocess import Popen, PIPE
import random
import os

def main():
    n_games = input("How many games do you want to play: ")
    p1 = input("Name of the player1: ")
    p2 = input("Name of the player2: ")
    p3 = input("Name of the player3: ")
    p4 = input("Name of the player4: ")
    info = input("Do you want to diplay the number of games played? [y/n]: ")
    victories = {p1:0, p2:0, p3:0, p4:0}
    print("\nPlaying... (this process might take some time)\n")
    for i in range(0, int(n_games)):
        n_random = random.randint(0, 100000000)
        nom_sortida = str(n_random)+".out"
        process = Popen(["./Game", p1, p2, p3, p4, "-s", str(n_random), "-i", "default.cnf", "-o", nom_sortida], stderr=PIPE)
        stderr = process.communicate()
        r = str(stderr).split()
        r = r[len(r)-6]
        if(info == "y"): print(str(i+1) + " of " + n_games + " played")
        victories[r] += 1
        os.remove(os.getcwd()+"/"+nom_sortida)

    print("\n----------------------")
    print("Victory rates:")
    print(p1 + " : " + str(100*(victories[p1]/int(n_games))) + " %")
    print(p2 + " : " + str(100*(victories[p2]/int(n_games))) + " %")
    print(p3 + " : " + str(100*(victories[p3]/int(n_games))) + " %")
    print(p4 + " : " + str(100*(victories[p4]/int(n_games))) + " %")
    print("----------------------\n")

if __name__ == "__main__":
	main()