#include <bits/stdc++.h>
using namespace std;

void spi_calc() {
    // Taking input from the user
    cout << "Enter number of subjects: " << endl;
    int n;
    cin >> n;
    vector<int> credit(n + 1);
    vector<int> grade(n + 1);

    for (int i = 1; i <= n; i++) {
        cout << "Enter credit and grade for subject " << i << ": " << endl;
        cin >> credit[i] >> grade[i];
        if (grade[i] < 0) {
            cout << "ERROR! Grade cannot be negative." << endl;
            return;
        }
    }

    // Calculation
    int tot_scr = 0, tot_cred = 0;
    for (int i = 1; i <= n; i++) {
        tot_scr += grade[i] * credit[i];
        tot_cred += credit[i];
    }

    // Result
    float SPI = 1.0 * tot_scr / tot_cred;
    cout << fixed << setprecision(2) << "Your SPI is: " << SPI << endl;
}

void cpi_calc() {
    // Taking input from the user
    cout << "Enter number of semesters: " << endl;
    int n;
    cin >> n;
    vector<int> credit(n + 1);
    vector<float> spi(n + 1);

    for (int i = 1; i <= n; i++) {
        cout << "Enter credit and SPI for semester " << i << ": " << endl;
        cin >> credit[i] >> spi[i];
        if (spi[i] < 0) {
            cout << "ERROR! SPI cannot be negative." << endl;
            return;
        }
    }

    // Calculation
    float tot_spi = 0;
    int tot_cred = 0;
    for (int i = 1; i <= n; i++) {
        tot_spi += spi[i] * credit[i];
        tot_cred += credit[i];
    }

    // Result
    float CPI = 1.0 * tot_spi / tot_cred;
    cout << fixed << setprecision(2) << "Your CPI is: " << CPI << endl;
}

int main() {
    spi_calc();
    cpi_calc();
    return 0;
}
