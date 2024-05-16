#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to perform summation in double precision (fp64)
double sum_fp64(const vector<double>& values) {
    double sum = 0.0;
    for (double val : values) {
        sum += val;
    }
    return sum;
}

// Function to perform summation in single precision (fp32)
float sum_fp32(const vector<float>& values) {
    float sum = 0.0f;
    for (float val : values) {
        sum += val;
    }
    return sum;
}

// Function to perform summation in half precision (fp16)
// Note: Implement your own fp16 arithmetic or use a library like half.hpp
// For simplicity, we'll assume a basic conversion for demonstration.
float sum_fp16(const vector<float>& values) {
    float sum = 0.0f;
    for (float val : values) {
        sum += val;
    }
    return sum;
}

// Recursive function to determine the summation strategy and encode the algorithm
string encode_algorithm(const vector<double>& values, int start, int end) {
    int n = end - start + 1;
    if (n == 1) {
        return "{d:" + to_string(start + 1) + "}";
    }

    double min_val = values[start];
    double max_val = values[start];
    for (int i = start + 1; i <= end; ++i) {
        min_val = min(min_val, values[i]);
        max_val = max(max_val, values[i]);
    }

    if (max_val == 0.0 || max_val <= 1e-15 || abs(max_val) >= 65536.0) {
        // Use half precision
        vector<float> fp16_values;
        for (int i = start; i <= end; ++i) {
            fp16_values.push_back(static_cast<float>(values[i]));
        }
        float sum = sum_fp16(fp16_values);
        return "{h:" + to_string(start + 1) + "," + to_string(end + 1) + "}";
    } else if (abs(max_val) <= 32768.0) {
        // Use single precision
        vector<float> fp32_values;
        for (int i = start; i <= end; ++i) {
            fp32_values.push_back(static_cast<float>(values[i]));
        }
        float sum = sum_fp32(fp32_values);
        return "{s:" + to_string(start + 1) + "," + to_string(end + 1) + "}";
    } else {
        // Use double precision
        return "{d:" + to_string(start + 1) + "," + to_string(end + 1) + "}";
    }
}

int main() {
    int N;
    cin >> N;

    vector<double> values(N);
    for (int i = 0; i < N; ++i) {
        cin >> values[i];
    }

    string algorithm = encode_algorithm(values, 0, N - 1);
    cout << algorithm << endl;

    return 0;
}

