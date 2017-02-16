# @param {Character[][]} board
# @return {Boolean}
def is_area_valid(area)
    counts = Hash.new(0)
    area.reject{|x| x == '.'}.each{ |grid| counts[grid] += 1 }
    counts.values.all? {|value| value <= 1}
end

# @param {Character[][]} board
# @return {Boolean}
def is_valid_sudoku(board)
    rows = board
    cols = (0...9).collect { |col_i|
      board.collect() { |row| row[col_i] }
    }
    blocks = (0...9).collect { |block_i|
      row_start = block_i / 3 * 3
      col_start = block_i % 3 * 3
      board[row_start...row_start + 3].collect {|row| row[col_start...col_start + 3]}.flatten
    }
    (rows + cols + blocks).all? {|area| is_area_valid(area)}
end
