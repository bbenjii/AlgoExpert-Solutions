def tournamentWinner(competitions, results):
    # Write your code here.
    teams = {}
    for i in range(len(results)):
        winner = ""
        if results[i] == 1:
            winner = competitions[i][0]
        else:
            winner = competitions[i][1]
        if winner not in teams:
            teams[winner] = 3
        else:
            teams[winner] = teams[winner] + 3

    winner = ""
    for team, point in teams.items():
        if winner == "":
            winner = team
        else:
            if point > teams[winner]:
                winner = team

    return winner
