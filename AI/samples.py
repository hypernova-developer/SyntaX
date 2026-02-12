from better_ai import AI_System_Architect
import numpy as np

def run_syntax_demo():
    # 0. Engine Initialization
    engine = AI_System_Architect()
    print("-" * 30)

    # 1. Deterministic ML Sample (Decision Tree)
    print("[SAMPLE 1] Training Decision Tree...")
    X = np.array([[1, 2], [3, 4], [5, 6], [7, 8]])
    y = np.array([0, 0, 1, 1])
    
    tree_model = engine.fit_tree(X, y)
    print("Tree Rules:\n", engine.model_to_string(tree_model))

    # 2. Deep Learning Sample (Neural Stack)
    print("\n[SAMPLE 2] Building Neural Brain...")
    brain = engine.build_dnn(shape=2, units=16)
    engine.master_train(brain, X, y, type='dl')
    print("Neural Network is ready for inference.")

    # 3. Evolutionary Sample (Genetic Mutation)
    print("\n[SAMPLE 3] Testing Evolutionary Logic...")
    population = np.array([0.1, 0.5, 0.9])
    mutated = engine.mutation_shuffle(population)
    print(f"Original: {population} -> Mutated: {mutated}")

    # 4. Rule Engine & Logic Sample (The "Saf Güç" Part)
    print("\n[SAMPLE 4] Applying Model Rules...")
    raw_value = 0.85
    threshold = 0.70
    is_safe = engine.add_rule_threshold(raw_value, threshold)
    
    if is_safe:
        print(f"Logic Result: Value {raw_value} passed the {threshold} limit. Access Granted.")
    else:
        print("Logic Result: Access Denied.")

    # 5. Data Processing Sample
    print("\n[SAMPLE 5] Benchmarking Speed...")
    start_point = engine.benchmark_speed(0) # Get reference
    # Simulate a heavy operation
    _ = [np.sin(i) for i in range(100000)]
    elapsed = engine.benchmark_speed(start_point)
    print(f"Operation completed in: {elapsed:.5f} seconds.")

    print("-" * 30)
    print("[RESULT] All SyntaX modules are operational.")

if __name__ == "__main__":
    run_syntax_demo()
