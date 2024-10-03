/*
Drew franke
3131934
Lab session: Wednesday 1:00pm
Lab Assignment: 04-2
Description: program performs temperature conversions between fahrenheit, celsius, and kelvin.
program also categorizes the temperature into predefined ranges based on its value and 
provides a weather advisory "Freezing," "Cold," "Comfortable," "Hot," "Extreme Heat".
*/

#include <stdio.h>

// function prototypes
float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);
float celsius_to_kelvin(float celsius);
float kelvin_to_celsius(float kelvin);
float fahrenheit_to_kelvin(float fahrenheit);
float kelvin_to_fahrenheit(float kelvin);
void categorize_temperature(float celsius);
void input_validation(int *input, int lower, int upper);
void temperature_conversion();

// main function
int main() {
    temperature_conversion();
    return 0;
}

// convert celsius to fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

// convert fahrenheit to celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

// convert celsius to kelvin
float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

// convert kelvin to celsius
float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

// convert fahrenheit to kelvin
float fahrenheit_to_kelvin(float fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

// convert kelvin to fahrenheit
float kelvin_to_fahrenheit(float kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

// categorize temperature based on Celsius and provide an advisory
void categorize_temperature(float celsius) {
    printf("Temperature category: ");
    if (celsius < 0) {
        printf("Freezing\n");
        printf("Weather advisory: Wear a heavy coat.\n");
    } else if (celsius >= 0 && celsius < 10) {
        printf("Cold\n");
        printf("Weather advisory: Wear a jacket.\n");
    } else if (celsius >= 10 && celsius < 25) {
        printf("Comfortable\n");
        printf("Weather advisory: You should feel comfortable.\n");
    } else if (celsius >= 25 && celsius < 35) {
        printf("Hot\n");
        printf("Weather advisory: Stay hydrated.\n");
    } else {
        printf("Extreme Heat\n");
        printf("Weather advisory: Stay indoors.\n");
    }
}

// validate input
void input_validation(int *input, int lower, int upper) {
    while (*input < lower || *input > upper) {
        printf("Invalid input. Please enter a valid option: ");
        scanf("%d", input);
    }
}

// temperature conversion function
void temperature_conversion() {
    float temperature, converted_temp;
    int current_scale, target_scale;

    // input temperature
    printf("Enter the temperature: ");
    scanf("%f", &temperature);

    // input the current temperature scale
    printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &current_scale);
    input_validation(&current_scale, 1, 3);

    // if kelvin, validate that the temperature is not negative
    if (current_scale == 3 && temperature < 0) {
        printf("Error: Temperature in Kelvin cannot be negative.\n");
        return;
    }

    // input the target temperature scale
    printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &target_scale);
    input_validation(&target_scale, 1, 3);

    // error if the user tries to convert to the same scale
    if (current_scale == target_scale) {
        printf("Error: Can not convert to the same temperature scale.\n");
        return;
    }

    // conversion logic based on the user's input
    switch (current_scale) {
        case 1: // celsius
            if (target_scale == 2) {
                converted_temp = celsius_to_fahrenheit(temperature);
                printf("Converted temperature: %.2fF\n", converted_temp);
            } else if (target_scale == 3) {
                converted_temp = celsius_to_kelvin(temperature);
                printf("Converted temperature: %.2fK\n", converted_temp);
            }
            categorize_temperature(temperature);
            break;

        case 2: // fahrenheit
            if (target_scale == 1) {
                converted_temp = fahrenheit_to_celsius(temperature);
                printf("Converted temperature: %.2fC\n", converted_temp);
                categorize_temperature(converted_temp);
            } else if (target_scale == 3) {
                converted_temp = fahrenheit_to_kelvin(temperature);
                printf("Converted temperature: %.2fK\n", converted_temp);
                categorize_temperature(fahrenheit_to_celsius(temperature));
            }
            break;

        case 3: // kelvin
            if (target_scale == 1) {
                converted_temp = kelvin_to_celsius(temperature);
                printf("Converted temperature: %.2fC\n", converted_temp);
                categorize_temperature(converted_temp);
            } else if (target_scale == 2) {
                converted_temp = kelvin_to_fahrenheit(temperature);
                printf("Converted temperature: %.2fF\n", converted_temp);
                categorize_temperature(kelvin_to_celsius(temperature));
            }
            break;
    }
}
