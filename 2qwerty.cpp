# myalgorithm_final.py  (Baseline + Local-Search 개선)

import time, random, importlib, util

# baseline_20250719.zip 의 myalgorithm.py 를 baseline_mod 로 import
import baseline_mod  # 같은 폴더에 'baseline_mod.py' 로 복사해 두세요!

def algorithm(prob_info, timelimit=60):
    start = time.time()

    # ① Baseline 실행 – 시간의 50%만 사용
    base_solution = baseline_mod.algorithm(prob_info, timelimit=timelimit * 0.5)

    chk = util.check_feasibility(prob_info, base_solution)
    if not chk['feasible']:
        # Baseline 도 infeasible 이면 그대로 반환
        return base_solution

    best_obj   = chk['obj']
    solution   = {p: list(base_solution[p]) for p in base_solution}
    flat_index = [(p, i) for p in solution for i in range(len(solution[p]))]

    # ② Swap + Insert Local-Search
    ITER = 120
    while ITER > 0 and time.time() - start < timelimit * 0.90:
        ITER -= 1
        if len(flat_index) < 2:
            break

        # 두 개의 (port, route_idx) 무작위 선택
        (p1, i1), (p2, i2) = random.sample(flat_index, 2)

        new_solution = {p: list(solution[p]) for p in solution}
        (route1, d1) = new_solution[p1][i1]
        (route2, d2) = new_solution[p2][i2]

        # demand ID 교환
        new_solution[p1][i1] = (route1, d2)
        new_solution[p2][i2] = (route2, d1)

        chk2 = util.check_feasibility(prob_info, new_solution)
        if chk2['feasible'] and chk2['obj'] < best_obj:
            # 개선되면 채택
            solution, best_obj = new_solution, chk2['obj']

    return solution
