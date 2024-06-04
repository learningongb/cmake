#pragma once

#include <stdexcept>

#include "board.h"

template<std::size_t N>
class SimpleBoard : public IBoard
{
public:
    SimpleBoard() = default;
    ~SimpleBoard() = default;

    virtual std::pair<PositionType, PositionType> dimention() const override
    {
        return std::make_pair(PositionType{}, m_size);
    }

    virtual Mark mark(const PositionType& pos) const override
    {
        if ( pos.x < m_size.x && pos.y < m_size.y) {
            return m_marks[pos.x][pos.y];
        }
        throw new std::invalid_argument("Invalid position");
        return MARK_UNKNOWN;
    }

    virtual bool setMark(const PositionType& pos, const Mark& mark) override
    {
        if ( pos.x < m_size.x && pos.y < m_size.y) {
            m_marks[pos.x][pos.y] = mark;
            return true;
        }
        return false;
    }

    virtual bool hasEmptyPlace()
    {
        auto dimension = dimention();
        const auto& xmin = dimension.first.x;
        const auto& ymin = dimension.first.y;
        const auto& xmax = dimension.second.x;
        const auto& ymax = dimension.second.y;
        PositionType pos;
        for (int x = xmin; x < xmax; x++)
        {
            pos.x = x;
            for (int y = ymin; y < ymax; y++)
            {
                pos.y = y;
                if (mark(pos) == Mark::MARK_EMPTY)
                    return true;
            }
        }
        return false;
    }


private:
    PositionType m_size = {N, N};
    Mark m_marks[N][N] = {IBoard::MARK_EMPTY};
};