#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class FoodRatings {
    vector<string> foods;
    vector<string> cuisines;
    vector<int> ratings;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        this->foods = foods;
        this->cuisines = cuisines;
        this->ratings = ratings;
    }
    
    void changeRating(string food, int newRating) {
        for (int i = 0; i < this->foods.size(); i++){
            if (this->foods[i] == food){
                this->ratings[i] = newRating;
                break;
            }
        }
    }
    
    string highestRated(string cuisine) {
        // int highestRatedPos = 0, highestRate = 0;
        vector<string> cusine_foods;
        int highestRate = 0;
        string highest_rated_cusine_food;
        for (int i = 0; i < this->foods.size(); i++)
        {
            if (this->cuisines[i] == cuisine)
            {
                if (this->ratings[i] > highestRate)
                {
                    highest_rated_cusine_food = this->foods[i];
                    highestRate = this->ratings[i];
                }else if(this->ratings[i] == highestRate)
                {
                    highest_rated_cusine_food = min(highest_rated_cusine_food, this->foods[i]);
                }
            }
        }
        return highest_rated_cusine_food;
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
            [["a","b","c","d","e","f"],["k","k","k","k","k","k"],[12,5,8,1,18,6]],
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