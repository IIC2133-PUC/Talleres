import random

def generate_instructions(V: int, N: int):
    keys = list(range(1, N + 1))

    nodes = [(key, random.randint(1, N*2)) for key in keys]
    extract_orders = [(-1, -1)] * (V - N)

    instructions = nodes.copy()
    instructions.extend(extract_orders)

    random.shuffle(instructions)

    return instructions

def save_instructions(filename, instructions, V, N):
    with open(filename, 'w') as f:
        f.write(f'{V}\n')
        f.write(f'{N}\n')
        for key, value in instructions:
            f.write(f'{key} {value}\n')

if __name__ == '__main__':
    for i in range(5):
        V = random.randint(200, 500)
        N = random.randint(V-100, V-20)
        instructions = generate_instructions(V, N)
        save_instructions(f'tests/case_{i}.txt', instructions, V, N)