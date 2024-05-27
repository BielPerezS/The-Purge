#include "Player.hh"

/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME RAIDEN

struct PLAYER_NAME : public Player
{

    /**
     * Factory: returns a new instance of this class.
     * Do not modify this function.
     */
    static Player *factory()
    {
        return new PLAYER_NAME;
    }

    /**
     * Types and attributes for your player can be defined here.
     */
    const vector<Dir> dirs = {Up, Down, Right, Left};
    // posicion barricada y player asignado
    set<int, Pos> bs;

    // Pre en p siemprte hay un player
    Dir House(Pos &p, bool &posible)
    {
        queue<pair<Pos, Dir>> cua;
        cua.push({p, Down});
        int Yo = citizen(cell(p).id).player;
        vector<vector<bool>> visit(15, vector<bool>(30, false));
        bool base = true;
        visit[p.i][p.j] = true;

        while (not cua.empty())
        {

            Pos f = cua.front().first;

            Dir new_dir = cua.front().second;

            for (int dir = 0; dir < 4; ++dir)
            {

                Pos new_f = f + dirs[dir];

                if (pos_ok(new_f) and visit[new_f.i][new_f.j] == false and cell(new_f).type == Street and cell(new_f).id == -1 and (cell(new_f).resistance == -1 or cell(new_f).b_owner == Yo))
                {

                    visit[new_f.i][new_f.j] = true;

                    if (base)
                    {
                        new_dir = dirs[dir];
                    }

                    if (cell(new_f).b_owner == Yo)
                    {
                        posible = true;
                        return new_dir;
                    }

                    cua.push({new_f, new_dir});
                }
            }
            cua.pop();
            base = false;
        }
        posible = false;
        return Up;
    }

    Dir Bonus(Pos &p, const int &bonus)
    {
        queue<pair<Pos, Dir>> cua;
        cua.push({p, Down});
        vector<vector<bool>> visit(15, vector<bool>(30, false));
        bool base = true;
        visit[p.i][p.j] = true;

        while (not cua.empty())
        {

            Pos f = cua.front().first;

            Dir new_dir = cua.front().second;

            for (int dir = 0; dir < 4; ++dir)
            {

                Pos new_f = f + dirs[dir];

                if (pos_ok(new_f) and visit[new_f.i][new_f.j] == false and cell(new_f).type == Street and cell(new_f).id == -1 and cell(new_f).resistance == -1)
                {

                    visit[new_f.i][new_f.j] = true;

                    if (base)
                    {
                        new_dir = dirs[dir];
                    }

                    if (cell(new_f).bonus == bonus)
                    {
                        return new_dir;
                    }

                    cua.push({new_f, new_dir});
                }
            }
            cua.pop();
            base = false;
        }
        return Up;
    }

    Dir Weapon(Pos &p, const int &weapon, bool &found)
    {
        queue<pair<Pos, Dir>> cua;
        cua.push({p, Down});
        vector<vector<bool>> visit(15, vector<bool>(30, false));
        bool base = true;
        visit[p.i][p.j] = true;

        while (not cua.empty())
        {

            Pos f = cua.front().first;

            Dir new_dir = cua.front().second;

            for (int dir = 0; dir < 4; ++dir)
            {

                Pos new_f = f + dirs[dir];

                if (pos_ok(new_f) and visit[new_f.i][new_f.j] == false and cell(new_f).type == Street and cell(new_f).resistance == -1 and cell(new_f).id == -1)
                {

                    visit[new_f.i][new_f.j] = true;

                    if (base)
                    {
                        new_dir = dirs[dir];
                    }

                    if (cell(new_f).weapon == weapon)
                    {
                        found = true;
                        return new_dir;
                    }

                    cua.push({new_f, new_dir});
                }
            }
            cua.pop();
            base = false;
        }
        found = false;
        return Up;
    }

    Dir Weapon2(Pos &p, const int &weapon, bool &found,int& fdist)
    {
        queue<pair<Pos, Dir>> cua;
        cua.push({p, Down});
        vector<vector<bool>> visit(15, vector<bool>(30, false));
        vector<vector<int>> Md(15, vector<int>(30, -1));
        bool base = true;
        visit[p.i][p.j] = true;
        Md[p.i][p.j] = 0;
        while (not cua.empty())
        {

            Pos f = cua.front().first;

            Dir new_dir = cua.front().second;

            int dist = Md[f.i][f.j];

            for (int dir = 0; dir < 4; ++dir)
            {

                Pos new_f = f + dirs[dir];

                if (pos_ok(new_f) and visit[new_f.i][new_f.j] == false and cell(new_f).type == Street and cell(new_f).resistance == -1 and cell(new_f).id == -1)
                {

                    visit[new_f.i][new_f.j] = true;
                    Md[new_f.i][new_f.j] = dist + 1;

                    if (base)
                    {
                        new_dir = dirs[dir];
                    }

                    if (cell(new_f).weapon == weapon)
                    {
                        found = true;
                        fdist = Md[new_f.i][new_f.j];
                        return new_dir;
                    }

                    cua.push({new_f, new_dir});
                }
            }
            cua.pop();
            base = false;
        }
        fdist = -1;
        found = false;
        return Up;
    }

    Dir KillBNoBar(Pos &p)
    {
        int MyID = citizen(cell(p).id).player;
        queue<pair<Pos, Dir>> cua;
        cua.push({p, Down});
        vector<vector<bool>> visit(15, vector<bool>(30, false));
        bool base = true;
        visit[p.i][p.j] = true;

        while (not cua.empty())
        {

            Pos f = cua.front().first;

            Dir new_dir = cua.front().second;

            for (int dir = 0; dir < 4; ++dir)
            {

                Pos new_f = f + dirs[dir];

                if (pos_ok(new_f) and visit[new_f.i][new_f.j] == false and cell(new_f).type == Street and cell(new_f).resistance == -1)
                {

                    visit[new_f.i][new_f.j] = true;

                    if (base)
                    {
                        new_dir = dirs[dir];
                    }

                    if (cell(new_f).id != -1 and citizen(cell(new_f).id).player != MyID and citizen(cell(new_f).id).type == Builder)
                    {
                        return new_dir;
                    }

                    cua.push({new_f, new_dir});
                }
            }
            cua.pop();
            base = false;
        }
        return Left;
    }

    Dir KillAnyNoBarLastGun(Pos &p)
    {
        int MyID = citizen(cell(p).id).player;
        int minpoints = 10000;
        int worstplayer = 10;
        for (int i = 0; i < 4; ++i)
        {
            if (i != MyID)
            {
                if (score(i) < minpoints)
                {
                    minpoints = score(i);
                    worstplayer = i;
                }
            }
        }
        queue<pair<Pos, Dir>> cua;
        cua.push({p, Down});
        vector<vector<bool>> visit(15, vector<bool>(30, false));
        bool base = true;
        visit[p.i][p.j] = true;

        while (not cua.empty())
        {

            Pos f = cua.front().first;

            Dir new_dir = cua.front().second;

            for (int dir = 0; dir < 4; ++dir)
            {

                Pos new_f = f + dirs[dir];

                if (pos_ok(new_f) and visit[new_f.i][new_f.j] == false and cell(new_f).type == Street and cell(new_f).resistance == -1 and (cell(new_f).id == -1 or (cell(new_f).id != -1 and citizen(cell(new_f).id).player == worstplayer)))

                {

                    visit[new_f.i][new_f.j] = true;

                    if (base)
                    {
                        new_dir = dirs[dir];
                    }

                    if (cell(new_f).id != -1 and citizen(cell(new_f).id).player != MyID and citizen(cell(new_f).id).type == Builder and citizen(cell(new_f).id).player == worstplayer)
                    {
                        return new_dir;
                    }

                    cua.push({new_f, new_dir});
                }
            }
            cua.pop();
            base = false;
        }
        return Left;
    }

    Dir KillWNoBar(Pos &p)
    {
        int MyID = citizen(cell(p).id).player;
        queue<pair<Pos, Dir>> cua;
        cua.push({p, Down});
        vector<vector<bool>> visit(15, vector<bool>(30, false));
        bool base = true;
        visit[p.i][p.j] = true;

        while (not cua.empty())
        {

            Pos f = cua.front().first;

            Dir new_dir = cua.front().second;

            for (int dir = 0; dir < 4; ++dir)
            {

                Pos new_f = f + dirs[dir];

                if (pos_ok(new_f) and visit[new_f.i][new_f.j] == false and cell(new_f).type == Street and cell(new_f).resistance == -1)
                {

                    visit[new_f.i][new_f.j] = true;

                    if (base)
                    {
                        new_dir = dirs[dir];
                    }

                    if (cell(new_f).id != -1 and citizen(cell(new_f).id).player != MyID and citizen(cell(new_f).id).type == Warrior and citizen(cell(new_f).id).weapon != Bazooka)
                    {
                        return new_dir;
                    }

                    cua.push({new_f, new_dir});
                }
            }
            cua.pop();
            base = false;
        }
        return Left;
    }

    Dir KillWNoBarLast(Pos &p)
    {
        int MyID = citizen(cell(p).id).player;
        int minpoints = 10000;
        int worstplayer = 10;
        for (int i = 0; i < 4; ++i)
        {
            if (i != MyID)
            {
                if (score(i) < minpoints)
                {
                    minpoints = score(i);
                    worstplayer = i;
                }
            }
        }
        queue<pair<Pos, Dir>> cua;
        cua.push({p, Down});
        vector<vector<bool>> visit(15, vector<bool>(30, false));
        bool base = true;
        visit[p.i][p.j] = true;

        while (not cua.empty())
        {

            Pos f = cua.front().first;

            Dir new_dir = cua.front().second;

            for (int dir = 0; dir < 4; ++dir)
            {

                Pos new_f = f + dirs[dir];

                if (pos_ok(new_f) and visit[new_f.i][new_f.j] == false and cell(new_f).type == Street and cell(new_f).resistance == -1 and
                    (cell(new_f).id == -1 or (cell(new_f).id != -1 and citizen(cell(new_f).id).player == worstplayer)))
                {

                    visit[new_f.i][new_f.j] = true;

                    if (base)
                    {
                        new_dir = dirs[dir];
                    }

                    if (cell(new_f).id != -1 and citizen(cell(new_f).id).player != MyID and citizen(cell(new_f).id).type == Warrior and citizen(cell(new_f).id).weapon != Bazooka)
                    {
                        return new_dir;
                    }

                    cua.push({new_f, new_dir});
                }
            }
            cua.pop();
            base = false;
        }
        return Left;
    }

    Dir KillAnyNoBar(Pos &p, WeaponType MyW)
    {
        int MyID = citizen(cell(p).id).player;
        queue<pair<Pos, Dir>> cua;
        cua.push({p, Down});
        vector<vector<bool>> visit(15, vector<bool>(30, false));
        bool base = true;
        visit[p.i][p.j] = true;

        while (not cua.empty())
        {

            Pos f = cua.front().first;

            Dir new_dir = cua.front().second;

            for (int dir = 0; dir < 4; ++dir)
            {

                Pos new_f = f + dirs[dir];

                if (pos_ok(new_f) and visit[new_f.i][new_f.j] == false and cell(new_f).type == Street and cell(new_f).resistance == -1 and (cell(new_f).id == -1 or (cell(new_f).id != -1 and citizen(cell(new_f).id).player != MyID and (citizen(cell(new_f).id).type == Builder or (citizen(cell(new_f).id).type == Warrior and citizen(cell(new_f).id).weapon < MyW)))))
                {

                    visit[new_f.i][new_f.j] = true;

                    if (base)
                    {
                        new_dir = dirs[dir];
                    }

                    if (cell(new_f).id != -1 and citizen(cell(new_f).id).player != MyID and (citizen(cell(new_f).id).type == Builder or (citizen(cell(new_f).id).type == Warrior and citizen(cell(new_f).id).weapon < MyW)))
                    {
                        return new_dir;
                    }

                    cua.push({new_f, new_dir});
                }
            }
            cua.pop();
            base = false;
        }
        return Left;
    }

    Dir KillFirstNoBar(Pos &p, WeaponType MyW, int &IDFirst)
    {
        int MyID = citizen(cell(p).id).player;
        queue<pair<Pos, Dir>> cua;
        cua.push({p, Down});
        vector<vector<bool>> visit(15, vector<bool>(30, false));
        bool base = true;
        visit[p.i][p.j] = true;

        while (not cua.empty())
        {

            Pos f = cua.front().first;

            Dir new_dir = cua.front().second;

            for (int dir = 0; dir < 4; ++dir)
            {

                Pos new_f = f + dirs[dir];

                if (pos_ok(new_f) and visit[new_f.i][new_f.j] == false and cell(new_f).type == Street and cell(new_f).resistance == -1 and
                    (cell(new_f).id == -1 or
                     (cell(new_f).id != -1 and
                      citizen(cell(new_f).id).player != MyID and citizen(cell(new_f).id).player == IDFirst and (citizen(cell(new_f).id).type == Builder or (citizen(cell(new_f).id).type == Warrior and citizen(cell(new_f).id).weapon < MyW)))))
                {

                    visit[new_f.i][new_f.j] = true;

                    if (base)
                    {
                        new_dir = dirs[dir];
                    }

                    if (cell(new_f).id != -1 and citizen(cell(new_f).id).player != MyID and citizen(cell(new_f).id).player == IDFirst and (citizen(cell(new_f).id).type == Builder or (citizen(cell(new_f).id).type == Warrior and citizen(cell(new_f).id).weapon < MyW)))
                    {
                        return new_dir;
                    }

                    cua.push({new_f, new_dir});
                }
            }
            cua.pop();
            base = false;
        }
        return Left;
    }
    /**
     * Play method, invoked once per each round.
     */
    virtual void play()
    {

        // EN LAS ULTIMAS 5 RONDAS HACER QUE CONTRUYAN CASETA Y SE METAN
        // Y FULL PRIO HEAL
        // SI TIENE TODO ESO A POR PASTA
        vector<int> b = builders(me());
        int house = 0;

        for (int id : b)
        {
            Pos p = citizen(id).pos;
            Dir Go = dirs[random(0, 3)];
            bool posible = true;

            if (is_day())
            {
                // crea barricada en las ultimas 5 rondas
                if (
                    ((round() >= 20 and round() <= 24) or (round() >= 120 and round() <= 124) or (round() >= 220 and round() <= 224) or (round() >= 70 and round() <= 74) or (round() >= 170 and round() <= 174)) and house < 3)
                {
                    bool able = false;
                    for (int i = 0; i < 4; ++i)
                    {
                        if (pos_ok(p + dirs[i]) and cell(p + dirs[i]).type != Building and cell(p + dirs[i]).id == -1)
                        {

                            Go = dirs[i];
                            break;
                        }
                    }

                    build(id, Go);
                    ++house;
                }
                // sino esta full life se cura
                else if (citizen(id).life < 60)
                    Go = Bonus(p, 1);
                // money $$
                else
                    Go = Bonus(p, 0);
                // move
                if (pos_ok(p + Go) and posible)
                    move(id, Go);
            }
            else if (is_night())
            {
                if (cell(p).resistance == -1)
                {
                    bool posible = false;
                    Go = House(p, posible);
                    if (!posible)
                    {
                        if (citizen(id).life < 60)
                            Go = Bonus(p, 1);
                        else
                            Go = Bonus(p, 0);
                    }
                    if (pos_ok(p + Go))
                        move(id, Go);
                }
            }
        }

        // SI NO SOMOS PRIMERO VAMOS A POR EL PRIMERO //   ELSE VAMOS A POR EL MAS CERCANO
        vector<int> w = warriors(me());
        for (int id : w)
        {
            Pos p = citizen(id).pos;
            Dir Go;
            // NEW: HACER QUE PERSIGAN 5 RONDAS ANTES
            //MIRAR SI VALE LA PENA PERSEGUIR O SI SU ITEM ESTABA A MENOS IGUAL de 5 de DISTANCIA
            if ((
                    (round() >= 20 and round() <= 24) or (round() >= 120 and round() <= 124) or
                    (round() >= 220 and round() <= 224) or (round() >= 70 and round() <= 74) or
                    (round() >= 170 and round() <= 174)) and citizen(id).weapon != Bazooka)
            {
                Go = KillAnyNoBar(p,citizen(id).weapon);
            }

            if (is_day())
            {
                bool found = true;
                if (citizen(id).life != 100)
                    Go = Bonus(p, 1);
                else if (citizen(id).weapon == Gun)
                {
                    // busca bazooka
                    Go = Weapon(p, 2, found);
                    // si no hi ha va a matar per la nit
                    if (!found)
                        Go = KillAnyNoBar(p, citizen(id).weapon);
                }

                else if (citizen(id).weapon == Bazooka)
                    Go = KillAnyNoBar(p, citizen(id).weapon);

                else
                {
                    Go = Weapon(p, 2, found);
                    if (!found)
                    {
                        bool found2 = false;
                        Go = Weapon(p, 1, found2);
                        if (!found2)
                            Go = KillAnyNoBar(p, citizen(id).weapon);
                    }
                }
            }

            // NOCHE
            else
            {
                bool found = false;
                Dir Go2 = Weapon(p, 2, found);
               // if (citizen(id).life < 100) Go = Bonus(p,1);
                if (found and citizen(id).weapon != Bazooka)
                {
                    Go = Go2;
                }
                else
                    Go = KillAnyNoBar(p, citizen(id).weapon);
            }

            if (pos_ok(p + Go))
                move(id, Go);
        }
    }
};

/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);