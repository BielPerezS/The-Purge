#include "Player.hh"



/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME NED

// DISCLAIMER: The following Demo player is *not* meant to do anything
// sensible. It is provided just to illustrate how to use the API.
// Please use AINull.cc as a template for your player.

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
  const vector<Dir> dirs = {Up, Down, Left, Right};

  // typedef vector<bool> vb;
  // typedef vector<vb> mb;
  //  devuelve la comida mas cercana posicion

  int foodDist(Pos p)
  {
    const vector<int> d_x = {0, 0, 1, -1};
    const vector<int> d_y = {1, -1, 0, 0};
    vector<vector<bool>> visit(30, vector<bool>(30, false));
    // mb visit(15, vb(30, false));
    queue<Pos> cua;
    cua.push(p);

    vector<vector<int>> Md(15, vector<int>(30, -1));
    Md[p.i][p.j] = 0;

    while (!cua.empty())
    {
      Pos f = cua.front();
      int i = f.i;
      int j = f.j;
      visit[i][j] = true;
      int dist = Md[i][j];

      for (int dir = 0; dir < 4; ++dir)
      {
        int new_i = i + d_x[dir];
        int new_j = j + d_y[dir];
        Pos new_f = {new_i, new_j};

        if ((new_i >= 0) and (new_i < 30) and (new_j >= 0) and (new_j < 15) and cell(new_f).type == Street 
            and cell(new_f).id == -1 and cell(new_f).resistance == -1 
            and visit[new_i][new_j] == false and pos_ok(new_f))
        {

          Md[new_i][new_j] = dist + 1;

          if (cell(new_f).bonus == Food)
            return Md[new_i][new_j];

          cua.push(new_f);
        }
      }
      cua.pop();
    }
    return 500;
  }

  int MoneyDist(Pos p)
  {
    const vector<int> d_x = {0, 0, 1, -1};
    const vector<int> d_y = {1, -1, 0, 0};
    vector<vector<bool>> visit(30, vector<bool>(30, false));
    // mb visit(15, vb(30, false));
    queue<Pos> cua;
    cua.push(p);

    vector<vector<int>> Md(15, vector<int>(30, -1));
    Md[p.i][p.j] = 0;

    while (!cua.empty())
    {
      Pos f = cua.front();
      int i = f.i;
      int j = f.j;
      visit[i][j] = true;
      int dist = Md[i][j];

      for (int dir = 0; dir < 4; ++dir)
      {
        int new_i = i + d_x[dir];
        int new_j = j + d_y[dir];
        Pos new_f = {new_i, new_j};

        if ((new_i >= 0) and (new_i < 15) and (new_j >= 0) and (new_j < 30) and cell(new_f).type == Street 
            and cell(new_f).id == -1 and cell(new_f).resistance == -1 
            and visit[new_i][new_j] == false and pos_ok(new_f))
        {

          Md[new_i][new_j] = dist + 1;

          if (cell(new_f).bonus == Money)
            return Md[new_i][new_j];

          cua.push(new_f);
        }
      }
      cua.pop();
    }
    return 500;
  }

  int BazookaDist(Pos p)
  {
    const vector<int> d_x = {0, 0, 1, -1};
    const vector<int> d_y = {1, -1, 0, 0};
    vector<vector<bool>> visit(30, vector<bool>(30, false));
    // mb visit(15, vb(30, false));
    queue<Pos> cua;
    cua.push(p);

    vector<vector<int>> Md(15, vector<int>(30, -1));
    Md[p.i][p.j] = 0;

    while (!cua.empty())
    {
      Pos f = cua.front();
      int i = f.i;
      int j = f.j;
      visit[i][j] = true;
      int dist = Md[i][j];

      for (int dir = 0; dir < 4; ++dir)
      {
        int new_i = i + d_x[dir];
        int new_j = j + d_y[dir];
        Pos new_f = {new_i, new_j};

        if ((new_i >= 0) and (new_i < 15) and (new_j >= 0) and (new_j < 30) 
            and cell(new_f).type == Street and cell(new_f).id == -1 and cell(new_f).resistance == -1 
            and visit[new_i][new_j] == false and pos_ok(new_f)) 
        {

          Md[new_i][new_j] = dist + 1;

          if (cell(new_f).weapon == Bazooka)
            return Md[new_i][new_j];

          cua.push(new_f);
        }
      }
      cua.pop();
    }
    return 450;
  }

  int GunDist(Pos p)
  {
    const vector<int> d_x = {0, 0, 1, -1};
    const vector<int> d_y = {1, -1, 0, 0};
    vector<vector<bool>> visit(30, vector<bool>(30, false));
    // mb visit(15, vb(30, false));
    queue<Pos> cua;
    cua.push(p);

    vector<vector<int>> Md(15, vector<int>(30, -1));
    Md[p.i][p.j] = 0;

    while (!cua.empty())
    {
      Pos f = cua.front();
      int i = f.i;
      int j = f.j;
      visit[i][j] = true;
      int dist = Md[i][j];

      for (int dir = 0; dir < 4; ++dir)
      {
        int new_i = i + d_x[dir];
        int new_j = j + d_y[dir];
        Pos new_f = {new_i, new_j};

        if ((new_i >= 0) and (new_i < 15) and (new_j >= 0) and (new_j < 30) 
            and cell(new_f).type == Street and cell(new_f).id == -1 and cell(new_f).resistance == -1 
            and visit[new_i][new_j] == false and pos_ok(new_f))
        {

          Md[new_i][new_j] = dist + 1;

          if (cell(new_f).weapon == Gun)
            return Md[new_i][new_j];

          cua.push(new_f);
        }
      }
      cua.pop();
    }
    return 450;
  }

  int PresaDist(Pos p)
  {
    const vector<int> d_x = {0, 0, 1, -1};
    const vector<int> d_y = {1, -1, 0, 0};
    vector<vector<bool>> visit(30, vector<bool>(30, false));
    // mb visit(15, vb(30, false));
    queue<Pos> cua;
    cua.push(p);

    vector<vector<int>> Md(15, vector<int>(30, -1));
    Md[p.i][p.j] = 0;

    while (!cua.empty())
    {
      Pos f = cua.front();
      int i = f.i;
      int j = f.j;
      visit[i][j] = true;
      int dist = Md[i][j];

      for (int dir = 0; dir < 4; ++dir)
      {
        int new_i = i + d_x[dir];
        int new_j = j + d_y[dir];
        Pos new_f = {new_i, new_j};

        if ((new_i >= 0) and (new_i < 15) and (new_j >= 0) and (new_j < 30) 
            and cell(new_f).type == Street and cell(new_f).resistance == -1 
            and visit[new_i][new_j] == false and pos_ok(new_f))
        {

          Md[new_i][new_j] = dist + 1;
          // si la cell hay alguien
          bool Presa = true;
          if (cell(new_f).id != -1)
          {
            // si es ocupado por alguien de nuestro equipo no se tiene en cuenta
            vector<int> w = warriors(me());
            for (int id : w)
            {
              if (cell(new_f).id == id)
                Presa = false;
            }
            vector<int> b = builders(me());
            for (int id : b)
            {
              if (cell(new_f).id == id)
                Presa = false;
            }
            // si en esa casilla hay un constructor enemigo vamos alli
            int id = cell(new_f).id;
            if (citizen(id).type == Builder and Presa)
              return Md[new_i][new_j];
          }

          cua.push(new_f);
        }
      }
      cua.pop();
    }
    return 450;
  }

  /**
   * Play method, invoked once per each round.
   */
  virtual void play()
  {

    // If nearly out of time, do nothing.
    double st = status(me());
    if (st >= 0.9)
      return;

    // If more than halfway through, do nothing.
    // if (round() > num_rounds()/2) return;

    // DIA
    if (is_day())
    {
      vector<int> b = builders(me());
      // Para todos los builders
      for (int id : b)
      {
        Pos p = citizen(id).pos;
        // si no tiene toda la vida bfs en busca comida
        // FUNCIONA
        if (citizen(id).life != 60)
        {
          if (foodDist(p) != 500)
          {
            pair<int, Dir> min = {500, Up};
            // miramos cual de los 4 caminos es el mas corto
            for (int i = 0; i < 1; ++i)
            {
              Dir d = dirs[0];
              // direccion valida + no building + no jugador
              if (pos_ok(p + d) and cell(p + d).type != Building and cell(p + d).id == -1 and cell(p + d).resistance == -1)
              {
                if (cell(p + d).bonus == Food and pos_ok(p + d))
                  move(id, d);
                else
                {
                  int dist = foodDist(p + d);
                  if (dist < min.first)
                    min = {dist, d};
                }
              }
            }
            if (pos_ok(p + min.second))
              move(id, min.second);
          }
        }
        // AÑADIR CRITERIOS DE CASAS EN UN FUTURO
        // Buscar dinero
        else
        {
          //42% DE CPU ESTO SOLO
          if (MoneyDist(p) != 500)
          {
            pair<int, Dir> min = {500, Up};
            // miramos cual de los 4 caminos es el mas corto
            for (int i = 0; i < 1; ++i)
            {
              Dir d = dirs[0];
              // direccion valida + no building + no jugador
              if (pos_ok(p + d) and cell(p + d).type != Building and cell(p + d).id == -1 and cell(p + d).resistance == -1)
              {
                if (cell(p + d).bonus == Money and pos_ok(p + d))
                  move(id, d);
                else
                {
                  int dist = MoneyDist(p + d);
                  if (dist < min.first)
                    min = {dist, d};
                }
              }
            }
            if (pos_ok(p + min.second))
              move(id, min.second);
          }
        }
      }

     
      vector<int> w = warriors(me());
      // para todos los warriors
          
      for (int id : w)
      {
        Pos p = citizen(id).pos;

        // miramos cual de los 4 caminos es el mas corto
        bool YesBazooka = true;
        // si no tenemos bazooka y quedan bazookas
        if (citizen(id).weapon != Bazooka)
        {
          int dist;
          // direccion valida + no building + no jugador
          pair<int, Dir> min = {450, Up};
          for (Dir d : dirs)
          {
            if (pos_ok(p + d) and cell(p + d).type != Building and cell(p + d).id == -1 and cell(p + d).resistance == -1)
            {
              if (cell(p + d).weapon == Bazooka and pos_ok(p+d))
                move(id, d);
              else
              {
                dist = BazookaDist(p + d);
                if (dist < min.first)
                  min = {dist, d};
              }
            }
          }
          if (pos_ok(p+min.second))
          move(id, min.second);
        }
        // hemos llegado aqui o bien xq no quedan bazookas o xq tenemos uno
        /*
        else if (citizen(id).weapon == Bazooka)
        {
          // Buscar vida
          if (citizen(id).life < 60)
          {
            pair<int, Dir> min = {500, Up};
            // miramos cual de los 4 caminos es el mas corto
            for (int i = 0; i < 1; ++i)
            {
              Dir d = dirs[0];
              // direccion valida + no building + no jugador
              if (pos_ok(p + d) and cell(p + d).type != Building and cell(p + d).id == -1 and cell(p + d).resistance == -1)
              {
                if (cell(p + d).bonus == Food and pos_ok(p+d))
                  move(id, d);
                else
                {
                  int dist = foodDist(p + d);
                  if (dist < min.first)
                    min = {dist, d};
                }
              }
            }
            if (pos_ok(p+min.second))
            move(id, min.second);
          }
          // Buscar dinero
          else
          {
            pair<int, Dir> min = {450, Up};
            // miramos cual de los 4 caminos es el mas corto
            for (int i = 0; i < 1; ++i)
            {
              Dir d = dirs[0];
              // direccion valida + no building + no jugador
              if (pos_ok(p + d) and cell(p + d).type != Building and cell(p + d).id == -1 and cell(p + d).resistance == -1)
              {
                if (cell(p + d).bonus == Money and pos_ok(p+d))
                  move(id, d);
                else
                {
                  int dist = MoneyDist(p + d);
                  if (dist < min.first)
                    min = {dist, d};
                }
              }
            }
            if (pos_ok(p+min.second))
            move(id, min.second);
          }
        }
        */
        // esto deberia incluir el caso No bazooka y No bazooka disponible
        
        /*
        else
        {
          // si tenemos pistola :)
          if (citizen(id).weapon == Gun)
          {
            // vida check
            if (citizen(id).life < 80)
            {
              pair<int, Dir> min = {450, Up};
              // miramos cual de los 4 caminos es el mas corto
              for (Dir d : dirs)
              {
                // direccion valida + no building + no jugador
                if (pos_ok(p + d) and cell(p + d).type != Building and cell(p + d).id == -1 and cell(p + d).resistance == -1)
                {
                  if (cell(p + d).bonus == Food and pos_ok(p + d))
                    move(id, d);
                  else
                  {
                    int dist = foodDist(p + d);
                    if (dist < min.first)
                      min = {dist, d};
                  }
                }
              }
              if (pos_ok(p+min.second))
              move(id, min.second);
            }
            // Buscar dinero
            else
            {
              pair<int, Dir> min = {450, Up};
              // miramos cual de los 4 caminos es el mas corto
              for (Dir d : dirs)
              {
                // direccion valida + no building + no jugador
                if (pos_ok(p + d) and cell(p + d).type != Building and cell(p + d).id == -1 and cell(p + d).resistance == -1)
                {
                  if (cell(p + d).bonus == Money and pos_ok(p + d))
                    move(id, d);
                  else
                  {
                    int dist = MoneyDist(p + d);
                    if (dist < min.first)
                      min = {dist, d};
                  }
                }
              }
              if (pos_ok(p + min.second))
              move(id, min.second);
            }
          }
          // si no tenemos pistola
          else if (citizen(id).weapon == Hammer)
          {
            // si existe pistola buscamos
            if (GunDist(p) != 450)
            {
              pair<int, Dir> min = {450, Up};
              for (Dir d : dirs)
              {
                if (pos_ok(p + d) and cell(p + d).type != Building and cell(p + d).id == -1 and cell(p + d).resistance == -1)
                {
                  if (cell(p + d).weapon == Gun and pos_ok(p+d))
                    move(id, d);
                  else
                  {
                    int dist = GunDist(p + d);
                    if (dist < min.first)
                      min = {dist, d};
                  }
                }
              }
              if (pos_ok(p + min.second))
              move(id, min.second);
            }
            // si no existe pistola buscamos dinero
            else
            {
              pair<int, Dir> min = {450, Up};
              // miramos cual de los 4 caminos es el mas corto
              for (Dir d : dirs)
              {
                // direccion valida + no building + no jugador
                if (pos_ok(p + d) and cell(p + d).type != Building and cell(p + d).id == -1 and cell(p + d).resistance == -1)
                {
                  if (cell(p + d).bonus == Money and pos_ok(p+d))
                    move(id, d);
                  else
                  {
                    int dist = MoneyDist(p + d);
                    if (dist < min.first)
                      min = {dist, d};
                  }
                }
              }
              if (pos_ok(p + min.second))
              move(id, min.second);
            }
          }
        }
        */
      }
    }

    // NOCHE
    /*
    else
    {
      // temporal buidlers
      vector<int> b = builders(me());
      // Para todos los builders
      for (int id : b)
      {
        Pos p = citizen(id).pos;
        // si no tiene toda la vida bfs en busca comida
        if (citizen(id).life < 100)
        {
          pair<int, Dir> min = {450, Up};
          // miramos cual de los 4 caminos es el mas corto
          for (Dir d : dirs)
          {
            // direccion valida + no building + no jugador
            if (pos_ok(p + d) and cell(p + d).type != Building and cell(p + d).id == -1 and cell(p + d).resistance == -1)
            {
              if (cell(p + d).bonus == Food)
                move(id, d);
              else
              {
                int dist = foodDist(p + d);
                if (dist < min.first)
                  min = {dist, d};
              }
            }
          }
          move(id, min.second);
        }

        // AÑADIR CRITERIOS DE CASAS EN UN FUTURO
        // Buscar dinero
        else
        {
          pair<int, Dir> min = {450, Up};
          // miramos cual de los 4 caminos es el mas corto
          for (Dir d : dirs)
          {
            // direccion valida + no building + no jugador
            if (pos_ok(p + d) and cell(p + d).type != Building and cell(p + d).id == -1 and cell(p + d).resistance == -1)
            {
              if (cell(p + d).bonus == Money)
                move(id, d);
              else
              {
                int dist = MoneyDist(p + d);
                if (dist < min.first)
                  min = {dist, d};
              }
            }
          }
          move(id, min.second);
        }
      }
      // At night take care of warriors
      vector<int> w = warriors(me());
      for (int id : w)
      {
        Pos p = citizen(id).pos;
        // De momento que ataquen unicamente a builders
        pair<int, Dir> min = {450, Up};
        // miramos cual de los 4 caminos es el mas corto
        for (Dir d : dirs)
        {
          // direccion valida + no building + no jugador
          if (pos_ok(p + d) and cell(p + d).type != Building and cell(p + d).id == -1 and cell(p + d).resistance == -1)
          {
            // si hay alguien alli enemigo builder
            if (cell(p + d).id != -1)
            {
              bool Presa = true;
              //miramos que no se nuestro
              vector<int> W = warriors(me());
              for (int id : W)
              {
                if (cell(p+d).id == id)
                  Presa = false;
              }
              vector<int> B = builders(me());
              for (int id : B)
              {
                if (cell(p+d).id == id)
                  Presa = false;
              }
              // si en esa casilla hay un constructor enemigo vamos alli
              int id = cell(p+d).id;
              if (citizen(id).type == Builder and Presa)
                move(id, d);
            }
            //buscamos distancia mas cercana presa
            else
            {
              int dist = PresaDist(p + d);
              if (dist < min.first)
                min = {dist, d};
            }
          }
        }
        move(id, min.second);
      }
    }
    */
  }
};

/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);
