#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
using namespace std;

class FoodRatings {
    unordered_map<string, int> foodRating;
    unordered_map<string, string> foodCuisines;
    // <cuisine, {{-rating, food}}
    unordered_map<string, set<pair<int, string>>> cuisineToSortedFoods;
    unordered_map<string, pair<int, string>> foodToPair;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++)
        {
            this->foodRating[foods[i]] = ratings[i];
            this->foodCuisines[foods[i]] = cuisines[i];
            pair<int, string> p = {-ratings[i], foods[i]};
            this->cuisineToSortedFoods[cuisines[i]].insert(p);
            this->foodToPair[foods[i]] = p;
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodCuisines[food];

        pair<int, string> oldFoodRatingPair = foodToPair[food];
        cuisineToSortedFoods[cuisine].erase(oldFoodRatingPair);
        
        pair<int, string> newFoodRatingPair = {-newRating, food};
        cuisineToSortedFoods[cuisine].insert(newFoodRatingPair);

        foodToPair[food] = newFoodRatingPair;
        foodRating[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return cuisineToSortedFoods[cuisine].begin()->second;
    }
};
/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */

int main() {
    /*
        ["FoodRatings","highestRated","changeRating","highestRated","changeRating","highestRated","highestRated","changeRating","highestRated","changeRating","highestRated"]
        [
            [
                ["a","b","c","d","e","f"],
                ["k","k","k","k","k","k"],
                [12, 5,  8,  1,  18,  6]
            ],
            ["k"],
            ["e",4],
            ["k"],
            ["d",11],
            ["k"],
            ["k"],
            ["e",8],
            ["k"],
            ["d",17],
            ["k"]
        ]
    */
    vector<string> foods = {"a","b","c","d","e","f"};
    vector<string> cuisines = {"k","k","k","k","k","k"};
    vector<int> ratings = {12,5,8,1,18,6};
    //op1
    FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
    //op2
    cout<<obj->highestRated("k")<<endl;
    //op3
    obj->changeRating("e",4);
    //op4
    cout<<obj->highestRated("k")<<endl;
    //op5
    obj->changeRating("d",11);
    //op6
    cout<<obj->highestRated("k")<<endl;
    //op7
    cout<<obj->highestRated("k")<<endl;
    //op8
    obj->changeRating("e",8);
    //op9
    cout<<obj->highestRated("k")<<endl;
    //op10
    obj->changeRating("d",17);
    //op11
    cout<<obj->highestRated("k")<<endl;
    return 0;
}