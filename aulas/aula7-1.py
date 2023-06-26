def _checkQueenCollision(queen1Pos, queen2Pos):
    row1 ,col1 = queen1Pos
    row2, col2 = queen2Pos
    if row1 == row2:
        return True
    if col1 == col2:
        return True
    if row1 + col1 == row2 + col2:
        return True
    if row1 - col1 == row2 - col2:
        return True
    return False
    

def _queenChessboard(i, otherQueens):
    if i == 8:
        return 1

    allPosiblePositions = 0
    
    for j in range(8):
        collided = False

        for queen in otherQueens:
            if _checkQueenCollision((i,j), queen):
                collided = True
        
        if not collided:
            otherQueens.add((i,j))
            allPosiblePositions += _queenChessboard(i+1, otherQueens)
            # remoção da rainha da lista para fazer o backtracking
            otherQueens.remove((i,j))

    return allPosiblePositions

def count8QueenChessboard():
    emptySet = set()
    return _queenChessboard(0, emptySet)

print(count8QueenChessboard())