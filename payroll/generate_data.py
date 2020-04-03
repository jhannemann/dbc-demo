# dbc-demo - A Design by Contract demonstration project
# Copyright (C) 2020 Dr.-Ing. Jens Hannemann - j.hannemann@ieee.org
#
# SPDX-License-Identifier: GPL-3.0-or-later

import random

def generate_ssn():
    ssnArea = random.randint(1, 899)
    while ssnArea==666:
        ssnArea = random.randint(1, 899)
    ssnGroup = random.randint(1, 99)
    ssnSerial = random.randint(1, 9999)
    ssn = '{0:03d}-{1:02d}-{2:04d}'.format(ssnArea, ssnGroup, ssnSerial)
    return ssn

# ensure generated SSNs are predictably pseudo-random
random.seed(0)
types = ('salaried', 'hourly')
payroll = []
ssns = []

# names have been generated via https://homepage.net/name_generator/
with open('names.csv') as file:
    for name in file:
        employee = name[:-1]
        ssn = generate_ssn()
        # make sure SSNs are unique
        while ssn in ssns:
            ssn = generate_ssn()
        ssns.append(ssn)
        employee += ' ' + ssn
        empType = random.choice(types)
        employee += ' ' + empType
        if empType == 'salaried':
            salary = random.randint(2000, 10000)
            employee += ' ' + str(salary)
        else:
            hours = random.randint(10, 160)
            rate = random.randint(8, 20)
            employee += ' ' + str(rate) + ' ' + str(hours)
        payroll.append(employee)
        
with open('payroll.csv', 'w') as file:
    for employee in payroll:
        print(employee)
        file.write(employee)
        file.write('\n')
