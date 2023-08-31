import random

class Villain:
    def __init__(self, name, health=100, energy=500, shield=0):
        self.name = name
        self.health = health
        self.energy = energy
        self.shield = shield

    def choose_action(self):
        pass 
class Gru(Villain):
    health=100
    energy=500
    def choose_action(self):
        if self.health < 30 and self.energy <= 50:#GRU health<30:as one of Vector weapons:its damage =22,GRU energy:as Min ENERGY to Use weapon is 50
            return "shield"
        else:
            return "weapon"

class Vector(Villain):
    health=100
    energy=500
    def choose_action(self):
        if self.health < 30 and self.energy <=40:##vector health<30:as one of GRU weapons:its damage =20,Vector energy:as Min ENERGY to Use weapon is 40
            return "shield"
        else:
            return "weapon"

class Weapon:
    def __init__(self, name, energy_value, damage):
        self.name = name
        self.energy_value = energy_value
        self.damage = damage
class Shield:
    def __init__(self, name, energy_value, save_percentage):
        self.name = name
        self.energy_value = energy_value
        self.save_percentage = save_percentage

gru_weapons = [
    Weapon("Freeze Gun", 50, 11),
    Weapon("Electric Prod", 88, 18),
    Weapon("Mega Magnet", 92, 10),
    Weapon("Kalman Missile", 120, 20),
]
vector_weapons = [
    Weapon("Laser Blasters", 40, 8),
    Weapon("Plasma Grenades", 56, 13),
    Weapon("Sonic Resonance Cannon", 100, 22),
]

gru_shields = [
    Shield("Energy-Projected BarrierGun", 20, 0.4),
    Shield("Selective Permeability", 50, 0.9),
]

vector_shields = [
    Shield("Energy Net Trap", 15, 0.32),
    Shield("Quantum Deflector", 40, 0.8),
]

gru = Gru("Gru")
vector = Vector("Vector")

# Simulate rounds
rounds = 0
while gru.health > 0 and vector.health > 0:
    rounds += 1
    print(f"Round {rounds}:")
    print(f"{gru.name} energy: {gru.energy}, health: {gru.health}")
    print(f"{vector.name} energy: {vector.energy}, health: {vector.health}")
# Gru's turn
    gru_action = gru.choose_action()
    if gru_action == "weapon":
        weapon = random.choice(gru_weapons)
        if weapon.energy_value <= gru.energy:
            gru.energy -= weapon.energy_value
            damage = weapon.damage
            if vector.shield > 0:
                damage = int(max((damage - damage*vector.shield), 1))
                vector.shield = 0
            vector.health -= damage
            print(f"{gru.name} uses {weapon.name} and makes {damage} damage to {vector.name}")
        else:
            print(f"{gru.name} doesn't have enough energy for {weapon.name}!")
    elif gru_action == "shield":
        shield = random.choice(gru_shields)
        if shield.energy_value <= gru.energy:
            gru.energy -= shield.energy_value
            gru.shield = shield.save_percentage
            print(f"{gru.name} uses {shield.name} and saves {int(gru.shield * 100)}% damage")
        else:
            print(f"{gru.name} doesn't have enough energy for {shield.name}!")
# Vector's turn
    vector_action = vector.choose_action()
    if vector_action == "weapon":
        weapon = random.choice(vector_weapons)
        if weapon.energy_value <= vector.energy:
            vector.energy -= weapon.energy_value
            damage = weapon.damage
            if gru.shield > 0:
                damage = int(max(damage -damage* gru.shield), 1)
                gru.shield = 0
            gru.health -= damage
            print(f"{vector.name} uses {weapon.name} and makes {damage} damage to {gru.name}")
        else:
            print(f"{vector.name} doesn't have enough energy for {weapon.name}!")
    elif vector_action == "shield":
        shield = random.choice(vector_shields)
        if shield.energy_value <= vector.energy:
            vector.energy -= shield.energy_value
            vector.shield = shield.save_percentage
            print(f"{vector.name} uses {shield.name} and saves {int(vector.shield * 100)}% damage")
        else:
            print(f"{vector.name} doesn't have enough energy for {shield.name}!")

        if gru.energy <20 and vector.energy<15:
            if gru.health>vector.health:
               print(f"{gru.name} wins!")
        else:
               print(f"{vector.name} wins!")
# Determine the winner
if gru.health <= 0:
    print(f"{vector.name} wins!")
else:
    print(f"{gru.name} wins!")