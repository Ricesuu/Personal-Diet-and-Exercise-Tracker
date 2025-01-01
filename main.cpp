/* 
 * File:   main.cpp
 * Author: ivans
 *
 * Created on May 6, 2024, 7:56 PM
 *  
 */

#include <cstdlib>
#include <iostream>
#include "User.h"
#include "Date.h"
#include "Tracker.h"
#include "Meal.h"
#include "Food.h"
#include "Exercise.h"
#include "Walking.h"
#include "Running.h"
#include "Freestyle.h"


using namespace std;

int main(int argc, char** argv) {
    // Create premade users
    vector<User*>* _users = new vector<User*>;
    User* Ivan = new User("Ivan", "Male", 20, 52, 175);
    User* KokKhinHeng = new User("Kok Khin Heng", "Male", 60, 75, 185);
    User* Tsuki = new User("Tsuki", "Female", 35, 45, 168);
    _users->push_back(Ivan);
    _users->push_back(KokKhinHeng);
    _users->push_back(Tsuki);

    User* currentUser = nullptr;
    bool isRunning = true;

    while(isRunning){
        //Welcome and login
        string isUserNew;
        cout << "Welcome to the Personal Diet and Exercise Tracker Application!\n";
        cout << "Are you a new user? (Y/N)\n";
        cout << "Enter your choice: ";
        cin >> isUserNew;

        if(isUserNew == "Y"){
            string name, gender;
            int age;
            double weight, height;

            cout << "Please enter your name: ";
            cin >> name;
            cout << "Please enter your gender: ";
            cin >> gender;
            cout << "Please enter your age: ";
            cin >> age;
            cout << "Please enter your weight (kg): ";
            cin >> weight;
            cout << "Please enter your height (cm): ";
            cin >> height;

            User* newUser = new User(name,gender,age,weight,height);
            _users->push_back(newUser);
            currentUser = (*_users).back();

        }else if(isUserNew == "N"){
            if(_users->empty()){
                cout << "No users found. Please register as a new user.\n";
            }else{
                string name;
                cout << "Please enter your name: ";
                cin.ignore();
                getline(cin, name);

                bool userFound = false;
                for(int i = 0; i < _users->size(); i++){
                    if((*_users)[i]->GetUserName() == name){
                        currentUser = (*_users)[i];
                        userFound = true;
                        break;
                    }
                }

                if(!userFound){
                    cout << "User not found. Please try again.\n";
                    continue;
                }
            }
        }else{
            cout << "Invalid input. Please enter Y for yes or N for no.\n";
            continue;
        }

        if(currentUser == NULL){
            cout << "No user assigned. Please try again\n";
            continue;
        }

        // Main menu
        do {
            cout << "\nWelcome, " << currentUser->GetUserName() << "!\n\n";
            cout << "Please choose what you would like to do:\n";
            cout << "1. User Profile Management\n";
            cout << "2. Nutrition Facts and Details Management\n";
            cout << "3. Daily Diet Tracking\n";
            cout << "4. Daily Exercise Tracking\n";
            cout << "5. Exit\n\n";
            cout << "Enter your choice: ";
        
            int choice;
            cin >> choice;
        
            switch(choice) {
                // User Profile Management Menu
                case 1:
                    int userProfileChoice;
                    do{
                    cout << "\n================== User Profile Management ==================\n\n";
                    cout << "1. Edit Personal Information\n";
                    cout << "2. Calculate BMI\n";
                    cout << "3. Set daily calorie target\n";
                    cout << "4. View daily calories\n";
                    cout << "5. Back\n\n";
                    cout << "Enter your choice: ";
        
                    cin >> userProfileChoice;
        
                    switch(userProfileChoice) {
                        case 1:{
                            string name, gender;
                            int age;
                            double weight, height;

                            cout << "\nPlease enter your new name: ";
                            cin >> name;
                            cout << "Please enter your new gender: ";
                            cin >> gender;
                            cout << "Please enter your new age: ";
                            cin >> age;
                            cout << "Please enter your new weight (kg): ";
                            cin >> weight;
                            cout << "Please enter your new height (cm): ";
                            cin >> height;

                            currentUser->EditPersonalInfo(name, gender, age, weight, height);
                            break;
                        }

                        case 2: {
                            double bmi = currentUser->CalculateBMI();
                            cout << "\nYour BMI is: " << bmi << " kg/m2"<<"\n";
                            break;
                        }

                        case 3:{
                            double target;
                            cout << "Please enter your daily calorie target: ";
                            cin >> target;
                            currentUser->SetDailyTarget(target);
                            break;
                        }

                        case 4: {
                            Date dateToday;
                            cout << "Please enter today's date (dd mm yyyy): ";
                            cin >> dateToday.day >> dateToday.month >> dateToday.year;
                            currentUser->CheckDailyCalories(dateToday);
                            break;
                        }
                        case 5:
                            break;
                        default:
                            cout << "\nInvalid choice. Please try again.\n";
                            break;
                    }
                    }while(userProfileChoice != 5);
                    break;
                // Nutrition Facts and Details Management Menu
                case 2: {
                    int nutritionChoice;
                    do{
                    cout << "================== Nutrition Facts and Details Management ==================\n\n";
                    cout << "1. Add Food and Nutrition Info\n";
                    cout << "2. Delete Food and Nutrition Info\n";
                    cout << "3. Search and View Food\n";
                    cout << "4. Back\n\n";
                    cout << "Enter your choice: ";
                
                    cin >> nutritionChoice;
                
                    switch(nutritionChoice) {
                        case 1: {
                            string foodName;
                            double calories, protein, carbs, fats;
                        
                            cout << "Enter the name of the food: ";
                            cin >> foodName;
                            cout << "Enter the number of calories: ";
                            cin >> calories;
                            cout << "Enter the amount of carbohydrates (g): ";
                            cin >> carbs;
                            cout << "Enter the amount of protein (g): ";
                            cin >> protein;
                            cout << "Enter the amount of fats (g): ";
                            cin >> fats;
                        
                            Food* newFood = new Food(foodName, calories, carbs, protein, fats);
                        
                            currentUser->AddFood(newFood);
                            break;
                        }
                        case 2: {
                            string foodName;

                            cout << "Enter the name of the food you want to delete: ";
                            cin >> foodName;
                            currentUser->RemoveFood(foodName);
                            cout << "Food has been removed.\n";
                            break;
                        }
                        case 3: {
                            string foodName;
                
                            cout << "Enter the name of the food you want to search and view: ";
                            cin >> foodName;
                            currentUser->SearchAndViewFood(foodName);
                            break;
                        }
                        default:
                            cout << "Invalid choice. Please try again.\n";
                            break;
                    }
                }while(nutritionChoice != 4);
                break;
                }
                // Daily Diet Tracking Menu
                case 3: {
                    int dietChoice;
                    do {
                        cout << "================== Diet Tracking ==================\n\n";
                        cout << "1. Add Meal Details\n";
                        cout << "2. Delete Meal Details\n";
                        cout << "3. View Monthly Calories Consumed\n";
                        cout << "4. Back\n\n";
                        cout << "Enter your choice: ";

                        cin >> dietChoice;

                        switch(dietChoice) {
                            case 1: {
                                string dateInput;
                                int type;
                                string foodName;
                            
                                cout << "Enter the date of the meal (format: DD MM YYYY): ";
                                cin >> ws; 
                                getline(cin, dateInput);
                            
                                Date mealDate;
                                sscanf(dateInput.c_str(), "%d %d %d", &mealDate.day, &mealDate.month, &mealDate.year);
                            
                                cout << "Enter the type of the meal (1. Breakfast, 2. Lunch, 3. Dinner, 4. Supper):";
                                cin >> type;
                                cin.ignore();
                            
                                MealType mealType;
                                switch(type) {
                                    case 1:
                                        mealType = Breakfast;
                                        break;
                                    case 2:
                                        mealType = Lunch;
                                        break;
                                    case 3:
                                        mealType = Dinner;
                                        break;
                                    case 4:
                                        mealType = Supper;
                                        break;
                                    default:
                                        cout << "Invalid meal type. Please try again.\n";
                                        break;
                                }
                            
                                cout << "Enter the name of the food you ate: ";
                                cin >> ws; 
                                getline(cin, foodName);
                            
                                Food* foodAte = currentUser->GetFoodForMeal(foodName);
                                currentUser->CreateMeal(mealDate, mealType, foodAte);
                                break;
                            }
                            case 2: {
                                string dateInput;
                                int type;
                            
                                cout << "Enter the date of the meal (format: DD MM YYYY): ";
                                cin >> ws; 
                                getline(cin, dateInput);
                            
                                Date mealDate;
                                sscanf(dateInput.c_str(), "%d %d %d", &mealDate.day, &mealDate.month, &mealDate.year);
                            
                                cout << "Enter the type of the meal (1. Breakfast, 2. Lunch, 3. Dinner, 4. Supper):";
                                cin >> type;
                                cin.ignore();
                            
                                MealType mealType;
                                switch(type) {
                                    case 1:
                                        mealType = Breakfast;
                                        break;
                                    case 2:
                                        mealType = Lunch;
                                        break;
                                    case 3:
                                        mealType = Dinner;
                                        break;
                                    case 4:
                                        mealType = Supper;
                                        break;
                                    default:
                                        cout << "Invalid meal type. Please try again.\n";
                                        break;
                                }
                            
                                cin.ignore(); 
                                currentUser->DeleteMeal(mealDate, mealType);
                                cout << "Meal has been removed.\n";
                                break;
                            }
                            case 3: {
                                int year, month;

                                cout << "Enter the year you want to view the monthly calories for: ";
                                cin >> year;

                                cout << "Enter the month you want to view the calories for (01-12): ";
                                cin >> month;

                                double monthlyCalories = currentUser->ViewMonthlyCaloriesOfYear(month, year);
                                cout << "Total calories for the month: " << monthlyCalories << " kcal\n";
                                break;
                            }
                            case 4:
                                break;
                            default:
                                cout << "Invalid choice. Please try again.\n";
                                break;
                        }
                    } while(dietChoice != 4);
                    break;
                }
                // Daily Exercise Tracking Menu
                case 4: {
                    int exerciseChoice;
                    do{
                    cout << "================== Exercise Tracking ==================\n\n";
                    cout << "1. Add Exercise Details\n";
                    cout << "2. View Monthly Calories Burned\n";
                    cout << "3. Back\n\n";

                    cout << "Enter your choice: ";
                    cin >> exerciseChoice;

                    switch(exerciseChoice) {
                        case 1: {
                            int exerciseType;
                            int duration;
                            Date exerciseDate;
                        
                            cout << "Select the type of the exercise:\n";
                            cout << "1. Walking\n";
                            cout << "2. Running\n";
                            cout << "3. Freestyle\n";
                            cout << "Enter your choice: ";
                            cin >> exerciseType;
                        
                            cout << "Enter the date of the exercise (DD MM YYYY): ";
                            cin >> exerciseDate.day >> exerciseDate.month >> exerciseDate.year;
                        
                            cout << "Enter the duration of the exercise in minutes: ";
                            cin >> duration;
                        
                            Exercise* exercise;
                            switch (exerciseType) {
                                case 1: {
                                    int stepsTaken;
                                    cout << "Enter the number of steps taken: ";
                                    cin >> stepsTaken;
                                    exercise = new Walking(exerciseDate, duration, stepsTaken);
                                    break;
                                }
                                case 2: {
                                    double distanceInKm;
                                    cout << "Enter the distance in kilometers: ";
                                    cin >> distanceInKm;
                                    exercise = new Running(exerciseDate, duration, distanceInKm);
                                    break;
                                }
                                case 3: {
                                    int BPM;
                                    cout << "Enter the BPM: ";
                                    cin >> BPM;
                                    exercise = new Freestyle(exerciseDate, duration, BPM);
                                    break;
                                }
                                default:
                                    cout << "Invalid choice. Please try again.\n";
                                    break;
                            }
                        
                            currentUser->UserAddExercise(exercise);
                            cout << "Exercise added successfully.\n";
                            break;
                        }
                        case 2: {
                            int year, month;

                            cout << "Enter the year you want to view the monthly calories burnt for: ";
                            cin >> year;

                            cout << "Enter the month you want to view the calories burnt for (01-12): ";
                            cin >> month;

                            double monthlyCaloriesBurnt = currentUser->ViewMonthlyCaloriesBurntOfYear(month, year);
                            cout << "Total calories burnt for the month: " << monthlyCaloriesBurnt << " kcal\n";
                            break;
                        }
                        case 3:
                            break;
                        default:
                            cout << "Invalid choice. Please try again.\n";
                            break;
                    }
                    }while(exerciseChoice != 3);
                    break;
                }
                //Exit
                case 5:
                    isRunning = false;
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
                    break;
            }
        } while(isRunning);
    }
    cout << "Thank you. Goodbye!\n";
    cout << "Press ENTER to exit.";
    cin.ignore();
    cin.get();
    
    return 0;
}

