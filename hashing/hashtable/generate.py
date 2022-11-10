import random
import os

def generate(N, M, input_file, query_file):
    used_ids = set()
    transactions = []
    for i in range(N):
        idx = random.randint(N*3, N*3.6)
        ammount = random.randint(1, 1000)
        transactions.append((idx, ammount))
        used_ids.add(idx)
    with open(input_file, 'w') as f:
        f.write(str(N) + '\n')
        for t in transactions:
            f.write(str(t[0]) + ' ' + str(t[1]) + '\n')
    with open(query_file, 'w') as f:
        f.write(str(M) + '\n')
        for i in range(M):
            idx = random.choice(list(used_ids))
            f.write(str(idx) + '\n')

if __name__ == '__main__':
    N = 200
    M = 80

    os.mkdir('tests')
    os.mkdir('tests/input')
    os.mkdir('tests/query')

    for i in range(5):
        input_file = 'tests/input/input{}.txt'.format(i)
        query_file = 'tests/query/query{}.txt'.format(i)
        generate(N, M, input_file, query_file)