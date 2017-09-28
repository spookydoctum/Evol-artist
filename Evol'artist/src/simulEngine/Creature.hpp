//
//  Creature.hpp
//  Evol'artist
//
//  Created by Emma Barme on 28/09/2017.
//  Copyright GNU General Public License v3.0
//

#ifndef Creature_hpp
#define Creature_hpp

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <utility>

//Forward declaration of World class
class World;

//Class for the creatures
class Creature
{
private:
    /**
     * Identifier of the creature
     */
    const int m_id;
    
    /**
     * Vision capacity of the creature
     */
    const int m_visionCap;
    
    /**
     * Maximum range of perception
     */
    int m_maxPercepCap;
    
    /**
     * Movement capacity of the creature
     */
    const int m_moveCap;
    
    /**
     * Horizontal coordinate of the creature in the world grid
     */
    int m_x;
    
    /**
     * Vertical coordinate of the creature in the world grid
     */
    int m_y;
    
    /**
     * Health of the creature
     */
    int m_health;
    
    /**
     * Hunger of the creature
     */
    int m_hunger;
    
    /**
     * Flattened matrix of the perceived local environment, centered on current position
     */
    std::vector<int> m_env;
    
public:
    /**
     * Creature constructor with specified coordinates
     * @param id Creature id
     * @param x Horizontal coordinate
     * @param y Vertical coordinate
     */
    Creature(const int id, const int x, const int y);
    
    /**
     * Creature constructor at random location
     * @param id Creature id
     */
    Creature(const int id);
    
    /**
     * Creature copy constructor
     * @param creature The Creature object to copy
     */
    Creature(const Creature& creature);
    
    Creature operator=(const Creature& creature);
    
    /**
     * Identifier accessor
     * @return m_id
     */
    const int getId() const;
    
    /**
     * Vision capacity accessor
     * @return m_visionCap
     */
    const int getVisionCap() const;
    
    /**
     * Maximum perception capacity accessor
     * @return m_maxPercepCap
     */
    const int getmaxPercepCap() const;
    
    /**
     * Coordinates accessor
     * @return The pair of horizontal and vertical coordinates
     */
    const std::pair<int, int> getCoord() const;
    
    /**
     * Check whether the creature should still be alive
     * @return False if the creature's health is negative
     */
    const bool isAlive() const;
    
    
    /**
     * Increase hunger as time goes
     */
    void growHungry();
    
    /**
     * Decrease health according to hunger
     */
    void hungerImpactHealth();
    
    /**
     * Feed creature to quell hunger
     * @param food The feeding power of the food
     */
    int feed(const int food);
    
    /**
     * Build local perception map
     * @param world A pointer to the World object
     */
    void perceiveLocalEnv(World const* world);
    
    /**
     * Move the creature towards the visible spot with highest feeding power
     * @return The pair of new horizontal and vertical coordinates
     */
    const std::pair<int, int> move();
    
};

#endif /* Creature_hpp */