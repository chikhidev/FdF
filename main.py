import sys
import math
import random
import statistics

creature_count = int(input())
for i in range(creature_count):
    creature_id, color, _type = [int(j) for j in input().split()]

creatures_positions = []

def next_spiral_position(center_x, center_y, radius, angle):
    x = center_x + radius * math.cos(angle)
    y = center_y + radius * math.sin(angle)
    return x, y

spiral_angle = 0
scanned_creature = False
right_pos_to_make_statistics = False
global_drone_x = 0  # Initialize global_drone_x

# game loop
while True:
    my_score = int(input())
    foe_score = int(input())
    my_scan_count = int(input())
    for _ in range(my_scan_count):
        creature_id = int(input())
    foe_scan_count = int(input())
    for _ in range(foe_scan_count):
        creature_id = int(input())
    my_drone_count = int(input())
    for _ in range(my_drone_count):
        drone_id, drone_x, drone_y, emergency, battery = [int(j) for j in input().split()]
        if drone_y == 0:
            scanned_top = False
            print("reached top!", file=sys.stderr)
            print("MOVE 5000 5000 0")
        global_drone_x = drone_x
    foe_drone_count = int(input())
    for _ in range(foe_drone_count):
        drone_id, drone_x, drone_y, emergency, battery = [int(j) for j in input().split()]
    drone_scan_count = int(input())
    for _ in range(drone_scan_count):
        drone_id, creature_id = [int(j) for j in input().split()]

    visible_creature_count = int(input())
    creatures_positions = []
    for _ in range(visible_creature_count):
        creature_id, creature_x, creature_y, _, _ = [int(j) for j in input().split()]
        creatures_positions.append((creature_x, creature_y))

    radar_blip_count = int(input())

    for _ in range(radar_blip_count):
        inputs = input().split()

    # Game control logic
    if my_score > foe_score:
        print("We're winning, keep up the good work!")
    elif my_score < foe_score:
        print("We're losing, let's step up our game!")
    else:
        print("It's a tie, let's take the lead!")

    # Drone control logic
    for _ in range(my_drone_count):
        if scanned_creature:
            print("MOVE 5000 5000 0")
        else:
            if creatures_positions:
                target_x = statistics.mean(x for x, _ in creatures_positions)
                target_y = statistics.mean(y for _, y in creatures_positions)
                print(f"MOVE {int(target_x)} {int(target_y)} 0")
            else:
                spiral_angle += 0.1
                target_x, target_y = next_spiral_position(5000, 5000, global_drone_x, spiral_angle)
                print(f"MOVE {int(target_x)} {int(target_y)} 1")