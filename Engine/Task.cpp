#include "Task.h"
#include "Utils.h"

/**
 *  This file is the cpp file for the Task class.
 *  @file Task.cpp
 *  @brief cpp file for Engine-Task
 *  @author Seonghyeon Park
 *  @date 2020-03-31
 */

/**
 * @fn Task::Task()
 * @brief the function of basic constructor of Task
 * @author Seonghyeon Park
 * @date 2020-04-01
 * @details 
 *  - None
 * @param none
 * @return none
 * @bug none
 * @warning none
 * @todo none
 */
Task::Task()
{
    
}

/**
 * @fn void Task::Task()
 * @brief the function of fundemental informed constructor of Task
 * @author Seonghyeon Park
 * @date 2020-04-01
 * @details 
 *  This constructor has all properties that define each tasks in ECU. 
 * @param task_name
 * @param task_id
 * @param period
 * @param deadline
 * @param wcet
 * @param bcet
 * @param offset
 * @param is_read
 * @param is_write
 * @param producer
 * @param consumer
 * @return Task
 * @bug none
 * @warning none
 * @todo none
 */
Task::Task(std::string task_name, int period, int deadline, int wcet,
            int bcet, int offset, bool is_read, bool is_write, int ecu_id)
{
    /**
     * Member variable initializaion
     */
    m_task_name = task_name;
    m_task_id = vectors::task_vector.size();
    m_period = period;
    m_deadline = deadline;
    m_wcet = wcet;
    m_bcet = bcet;
    m_offset = offset;
    m_is_read = is_read;
    m_is_write = is_write;

    for(auto iter = vectors::ecu_vector.begin(); iter != vectors::ecu_vector.end(); iter++)
    {
        if(ecu_id == iter->get()->get_ECU_id())
        {
            m_ecu = *iter;
        }
    }
}

/**
 * @fn Task::~Task()
 * @brief the function of basic destructor of Task
 * @author Seonghyeon Park
 * @date 2020-04-01
 * @details 
 *  - None
 * @param none
 * @return none
 * @bug none
 * @warning none
 * @todo none
 */
Task::~Task()
{

}

/**
 * @fn std::string get_task_name()
 * @brief Getter for task name
 * @author Seonghyeon Park
 * @date 2020-04-17
 * @details 
 *  - None
 * @param none
 * @return Task name
 * @bug none
 * @warning none
 * @todo none
 */
std::string Task::get_task_name()
{
    return m_task_name;
}

/**
 * @fn int get_task_id()
 * @brief Getter for task ID
 * @author Seonghyeon Park
 * @date 2020-04-17
 * @details 
 *  - None
 * @param none
 * @return Task ID
 * @bug none
 * @warning none
 * @todo none
 */
int Task::get_task_id()
{
    return m_task_id;
}

/**
 * @fn int get_period()
 * @brief Getter for task period
 * @author Seonghyeon Park
 * @date 2020-04-17
 * @details 
 *  - None
 * @param none
 * @return Task Period
 * @bug none
 * @warning none
 * @todo none
 */
int Task::get_period()
{
    return m_period;
}

/**
 * @fn int get_deadline()
 * @brief Getter for task deadline
 * @author Seonghyeon Park
 * @date 2020-04-17
 * @details 
 *  - None
 * @param none
 * @return Task Deadline
 * @bug none
 * @warning none
 * @todo none
 */
int Task::get_deadline()
{
    return m_deadline;
}

/**
 * @fn int get_wcet()
 * @brief Getter for task's worst case execution time
 * @author Seonghyeon Park
 * @date 2020-04-17
 * @details 
 *  - None
 * @param none
 * @return Task worst case execution time
 * @bug none
 * @warning none
 * @todo none
 */
int Task::get_wcet()
{
    return m_wcet;
}

/**
 * @fn int get_bcet()
 * @brief Getter for task's best case execution time
 * @author Seonghyeon Park
 * @date 2020-04-17
 * @details 
 *  - None
 * @param none
 * @return Task best case execution time
 * @bug none
 * @warning none
 * @todo none
 */
int Task::get_bcet()
{
    return m_bcet;
}

/**
 * @fn int get_offset()
 * @brief Getter for task's offset
 * @author Seonghyeon Park
 * @date 2020-04-17
 * @details 
 *  - None
 * @param none
 * @return Task offset
 * @bug none
 * @warning none
 * @todo none
 */
int Task::get_offset()
{
    return m_offset;
}

int Task::get_priority()
{
    return m_priority;    
}
/**
 * @fn int get_is_read()
 * @brief Getter for task's read constraint
 * @author Seonghyeon Park
 * @date 2020-04-17
 * @details 
 *  - None
 * @param none
 * @return Task read constraint
 * @bug none
 * @warning none
 * @todo none
 */
bool Task::get_is_read()
{
    return m_is_read;
}

/**
 * @fn int get_is_write()
 * @brief Getter for task's write constraint
 * @author Seonghyeon Park
 * @date 2020-04-17
 * @details 
 *  - None
 * @param none
 * @return Task write constraint
 * @bug none
 * @warning none
 * @todo none
 */
bool Task::get_is_write()
{
    return m_is_write;
}

std::shared_ptr<ECU> Task::get_ECU()
{
    return m_ecu;
}

std::vector<std::shared_ptr<Task>> Task::get_producers()
{
    return m_producers;
}

std::vector<std::shared_ptr<Task>> Task::get_consumers()
{
    return m_consumers;
}
/**
 * Setter member functions
 */
void Task::set_task_name(std::string task_name)
{
    m_task_name = task_name;
}

void Task::set_task_id(int task_id)
{
    m_task_id = task_id;
}
void Task::set_period(int period)
{
    m_period = period;
}
void Task::set_deadline(int deadline)
{
    m_deadline = deadline;
}
void Task::set_wcet(int wcet)
{
    m_wcet = wcet;
}
void Task::set_bcet(int bcet)
{
    m_bcet = bcet;
}
void Task::set_offset(int offset)
{
    m_offset = offset;
}
void Task::set_is_read(bool is_read)
{
    m_is_read = is_read;
}
void Task::set_is_write(bool is_write)
{
    m_is_write = is_write;
}
void Task::set_priority(int priority)
{
    m_priority = priority;
}

void Task::set_producers(std::vector<std::shared_ptr<Task>> producers)
{
    m_producers = producers;
}
void Task::set_consumers(std::vector<std::shared_ptr<Task>> consumers)
{
    m_consumers = consumers;
}
void Task::set_ECU(std::shared_ptr<ECU> ecu)
{
    m_ecu = ecu;
}

void Task::synchronize_producer_consumer_relation()
{
    /*
    for(auto iter = vectors::task_vector.begin(); iter != vectors::task_vector.end(); iter++)
    {
        if(iter->get)
        {
            _producers.push_back(); 
        }
    }
    */
}