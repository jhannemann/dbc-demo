import subprocess
from pylab import *

command = './ssntest'

output = subprocess.run([command], check=True, shell=False,
                        stdout=subprocess.PIPE)
output = output.stdout.decode()
print(output)
lines = output.split('\n')
line = lines[-3]
line = line.split(' ')
tests = ('passed', 'failed', 'skipped', 'blacklisted')
numbers = []
numbers.append(int(line[1]))
numbers.append(int(line[3]))
numbers.append(int(line[5]))
numbers.append(int(line[7]))
figure()
bar(tests, numbers)
show()
