from random import seed, randrange

class Activity:
    def __init__(self, start, end):
        self.start = start
        self.end = end

    def collides(self, other_activity):
        if self.start > other_activity.end or other_activity.start > self.end:
            return False
        return True

    def __str__(self) -> str:
        return str(self.start) + " until " + str(self.end)


# Time Complexity:
# O(2^n)
def _complete_search_aux(all_activites, idx, taken):
    if idx == len(all_activites):
        return len(taken), [all_activites[taken_idx] for taken_idx in taken]

    can_take = True
    for taken_idx in taken:
        if all_activites[idx].collides(all_activites[taken_idx]):
            can_take = False
            break

    if can_take:
        num_not_taking_this_activity, taken_1 = _complete_search_aux(all_activites, idx+1, taken)
        taken.append(idx)
        num_taking_this_activity, taken_2 = _complete_search_aux(all_activites, idx+1, taken)
        taken.pop()

        if num_not_taking_this_activity > num_taking_this_activity:
            return num_not_taking_this_activity, taken_1
        else:
            return num_taking_this_activity, taken_2

    return _complete_search_aux(all_activites, idx+1, taken)


# Time Complexity:
# O(nlog(n))
def _greedy_search(all_activities):
    all_activities.sort(key = lambda acitivity : acitivity.end)

    taken_activities = []
    for activity in all_activities:
        # can_take = True
        # for taken_activity in taken_activities:
        #    if activity.collides(taken_activity):
        #        can_take = False
        #        break
        # if can_take:
        #    taken_activities.append(activity)

        if len(taken_activities) == 0 or ( not activity.collides(taken_activities[-1]) ):
            taken_activities.append(activity)

    return len(taken_activities), taken_activities


def solve_activity_selection(all_activities):
    # return _complete_search_aux(all_activities, 0, [])
    return _greedy_search(all_activities)


# activities = [Activity(13, 16), Activity(15, 17.2), Activity(16.1, 17.3), Activity(17.35, 19), Activity(18.45, 19.15), Activity(19.1, 21)]
activities = []
seed(23)

for i in range(140000):
   a = randrange(0, 9999)
   b = randrange(1, 10000)

   if b < a:
       a, b = b, a

   if a == b:
       b += 1

   activities.append(Activity(a, b))

num, taken_activities = solve_activity_selection(activities)
print(num)
taken_activities.sort(key=lambda activity: activity.start)
for taken_activity in taken_activities:
    print(taken_activity)