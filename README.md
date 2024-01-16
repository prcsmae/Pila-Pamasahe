
# Pila Pamasahe?

Davao City Jeepney Fare Calculator: Pila Pamasahe?

Davao City's jeepney system lacks a standardized fare calculation method, resulting in confusion and disputes among passengers and drivers. The manual calculation process is error-prone and compromises safety. This project aims to mitigate these issues by developing a C-programmed Jeepney Fare Calculator, streamlining fare computation, and improving the overall commuting experience in the city.


## Authors
- Precious ([@prcsmae](github.com/prcsmae))
- Jodi ([@csjodes](github.com/csjodes))
- Cris ([@cristieneil](github.com/cristieneil))
- Chello ([@04Che](github.com/04che))


## Features

The user will be asked for different data to input that will be used by the program to calculate the total fare, namely:
- Name of the location at Point A and Point B
- Distance between Point A and Point B
- Type of Jeep (Non-Air Conditioned or Air Conditioned)
- Applicable Discount (Student, PWD, Senior Citizen, or None)
- Number of passengers
- If the user would like to calculate another fare

Based on these input data, the program will output in both the terminal and an external text file:
- The fare for each journey calculated
- Starting Point
- Ending Point
- Jeepney Type
- Applicable Discount
- Number of passengers
- Distance
- Fare Total (Base Fare, Additional Fare, Final Fare, and Total Fare (If more than one calculation))
## Installation

- Clone the repository
    ```bash
    git clone https://github.com/prcsmae/CMSC-18-Project.git
    ```
- Compile the Source Code:
    ```bash
    gcc JeepneyFareCalculator.c -o JeepneyFareCalculator
    ```

## Contributing

If you want to improve this project and contribute, here are the steps below.

- Fork the repository

- Create a new branch for your feature
```bash
(git checkout -b feature/new-feature).
```
- Commit your changes
```bash
(git commit -m "commit message").
```
- Push to the branch
- Open a pull request

