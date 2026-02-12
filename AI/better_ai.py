import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import tensorflow as tf
from tensorflow import keras
from sklearn import neighbors, tree, naive_bayes, ensemble
from sklearn.model_selection import train_test_split, KFold
from sklearn.metrics import accuracy_score, f1_score, roc_auc_score
import skfuzzy as fuzz
import mesa
import pygad
import os
import time
import random
import warnings
from tqdm import tqdm

# --- CORE ENGINE CONFIGURATION ---
warnings.filterwarnings('ignore')

class AI_System_Architect:
    def __init__(self):
        self.session_id = random.randint(1000, 9999)
        print(f"[SYSTEM] Engine active. Session: {self.session_id}")

    # --- 1. DETERMINISTIC MODELS (KNN, Tree, Bayes) ---
    def fit_knn(self, X, y, k=5): return neighbors.KNeighborsClassifier(n_neighbors=k).fit(X, y)
    def fit_tree(self, X, y): return tree.DecisionTreeClassifier().fit(X, y)
    def fit_naive_bayes(self, X, y): return naive_bayes.GaussianNB().fit(X, y)
    def fit_random_forest(self, X, y): return ensemble.RandomForestClassifier().fit(X, y)
    def get_feature_importance(self, model): return model.feature_importances_
    def predict_probabilities(self, model, X): return model.predict_proba(X)
    def prune_tree(self, X, y, ccp_alpha=0.01): return tree.DecisionTreeClassifier(ccp_alpha=ccp_alpha).fit(X, y)
    def model_to_string(self, model): return tree.export_text(model)

    # --- 2. DEEP NEURAL COMPUTATION ---
    def build_dnn(self, shape, units=512):
        model = keras.Sequential([
            keras.layers.Dense(units, activation='relu', input_shape=(shape,)),
            keras.layers.Dropout(0.2),
            keras.layers.Dense(units//2, activation='relu'),
            keras.layers.Dense(1, activation='sigmoid')
        ])
        model.compile(optimizer='adam', loss='binary_crossentropy', metrics=['accuracy'])
        return model
    def add_custom_layer(self, model, units, act='relu'): model.add(keras.layers.Dense(units, activation=act))
    def set_learning_rate(self, lr): return keras.optimizers.Adam(learning_rate=lr)
    def early_stopping_logic(self): return keras.callbacks.EarlyStopping(monitor='loss', patience=3)
    def get_layer_weights(self, model, index): return model.layers[index].get_weights()
    def compute_gradient(self, model, data): return tf.GradientTape() # Placeholder for custom training
    def tensor_reshape(self, data, target): return np.reshape(data, target)
    def evaluate_tensor_flow(self, model, X, y): return model.evaluate(X, y, verbose=0)

    # --- 3. HEURISTICS & EVOLUTION (GA, Ants, Fuzzy) ---
    def init_ga(self, f_func, g_count): return pygad.GA(num_generations=100, fitness_func=f_func, num_genes=g_count, num_parents_mating=10, sol_per_pop=20)
    def run_ga_engine(self, instance): instance.run()
    def get_best_genome(self, instance): return instance.best_solution()
    def fuzzy_membership(self, x, abc): return fuzz.trimf(x, abc)
    def ant_path_optimization(self, dist_matrix): pass # High-level path logic
    def evolve_population(self, pop): return np.sort(pop)
    def mutation_shuffle(self, data): return np.random.permutation(data)
    def get_fitness_curve(self, instance): return instance.plot_fitness()

    # --- 4. AGENT BASED DYNAMICS (Mesa) ---
    def create_grid(self, w, h): return mesa.space.MultiGrid(w, h, True)
    def add_to_schedule(self, model, agent): model.schedule.add(agent)
    def move_agent(self, model, agent, pos): model.grid.move_agent(agent, pos)
    def get_neighbors(self, model, pos): return model.grid.get_neighbors(pos, moore=True)
    def run_step(self, model): model.step()
    def batch_run(self, model, limit): 
        for _ in range(limit): model.step()
    def collect_agent_vars(self, model): return [a.unique_id for a in model.schedule.agents]
    def clear_grid(self, model): 
        for a in model.schedule.agents: model.grid.remove_agent(a)

    # --- 5. DATA PRE-PROCESSING & IO ---
    def quick_load(self, path): return pd.read_csv(path)
    def quick_save(self, df, name): df.to_csv(name, index=False)
    def handle_missing(self, df): return df.fillna(df.mean())
    def get_dummies(self, df): return pd.get_dummies(df)
    def scale_min_max(self, data): return (data - data.min()) / (data.max() - data.min())
    def split_data(self, X, y): return train_test_split(X, y, test_size=0.2)
    def filter_os_files(self, path): return [f for f in os.listdir(path) if f.endswith('.csv')]
    def benchmark_speed(self, start): return time.time() - start

    # --- 6. MODEL TRAINING & RULE ENGINE (CRITICAL) ---
    def master_train(self, model, X, y, type='ml'):
        """Global training interface for both ML and DL models."""
        if type == 'ml': return model.fit(X, y)
        else: return model.fit(X, y, epochs=10, verbose=1)

    def add_rule_threshold(self, value, threshold):
        """Logic rule: returns binary state based on threshold."""
        return 1 if value >= threshold else 0

    def apply_logical_filter(self, data, condition_func):
        """Applies a specific model rule across a dataset."""
        return [condition_func(x) for x in data]

    def validate_rule_set(self, predictions, rules):
        """Cross-checks model output against hardcoded logic rules."""
        return np.array([1 if p in rules else 0 for p in predictions])

    def export_inference_logic(self, model, filename):
        """Saves the logic gates of the model for production."""
        with open(filename, 'w') as f: f.write(str(model.get_params()))

    def hyperparameter_grid_search(self):
        """Template for finding optimal rule parameters."""
        pass 

    def inject_noise_for_robustness(self, data, level=0.05):
        """Trains the model to be tougher by adding Gaussian noise."""
        return data + np.random.normal(0, level, data.shape)

    def calculate_error_margin(self, y_true, y_pred):
        """Returns the raw error margin for rule calibration."""
        return np.abs(y_true - y_pred)

# --- EXECUTION ---
if __name__ == "__main__":
    engine = AI_System_Architect()
    print("[RESULT] 48 Functions Loaded. Pure Power Ready.")
