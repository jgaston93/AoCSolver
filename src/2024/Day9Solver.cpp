#include "Day9Solver.hpp"

#include "AoCSolverCommon.hpp"

namespace YEAR_2024::DAY_9
{

  void Solver::Initialize(const char *input_filename)
  {
    FILE *fp = fopen(input_filename, "r");

    if (fp != nullptr)
    {
      char line[AOC_SOLVER_COMMON::MAX_LINE_LENGTH] = {0};
      bool file_data = true;
      char c = 0;
      unsigned int position = 0;
      while ((c = fgetc(fp)) != EOF)
      {
        if (file_data)
        {
          m_id[m_file_count] = m_file_count;
          m_size[m_file_count] = c - '0';
          m_position[m_file_count] = position;
        }
        else
        {
          m_space[m_file_count] = c - '0';
          position += m_size[m_file_count] + m_space[m_file_count];
          m_file_count++;
        }

        file_data = !file_data;
      }
      fclose(fp);
      m_file_count++;

      for (int i = 0; i < m_file_count; i++)
      {
        printf("%u: %u %u %u\n", m_id[i], m_size[i], m_space[i], m_position[i]);
      }
    }
  }

  void Solver::Run()
  {
    unsigned int head = 0;
    unsigned int tail = m_file_count - 1;

    head = 0;
    tail = m_file_count - 1;

    Node *root = new Node();
    root->file_id = m_id[head];
    m_size[head]--;
    Node *node_ptr = root;

    while (head <= tail)
    {
      for (unsigned int i = 0; i < m_size[head]; i++)
      {
        node_ptr->next_node = new Node();
        node_ptr = node_ptr->next_node;
        node_ptr->file_id = m_id[head];
      }
      m_size[head] = 0;

      while (m_space[head] > 0 && m_size[tail] > 0)
      {
        node_ptr->next_node = new Node();
        node_ptr = node_ptr->next_node;
        node_ptr->file_id = m_id[tail];
        m_space[head]--;
        m_size[tail]--;
      }

      if (m_space[head] == 0)
        head++;
      if (m_size[tail] == 0)
        tail--;
    }

    unsigned long long int checksum = 0;
    node_ptr = root;
    unsigned int counter = 0;
    while (node_ptr != nullptr)
    {
      checksum += counter++ * node_ptr->file_id;
      // printf("%u", node_ptr->file_id);
      node_ptr = node_ptr->next_node;
    }
    printf("\nChecksum: %llu\n", checksum);
  }

} // namespace YEAR_2024::DAY_9
