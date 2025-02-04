namespace Evade
{
    class EvadeAPI
    {
        public:
            virtual bool is_enabled() = 0;
            virtual bool is_evading() = 0;
            virtual bool is_safe(float x, float y) = 0;
            virtual bool is_dangerous(float x, float y) = 0;

            virtual float calculate_damage() = 0;
            virtual float time_to_hit(float x, float y) = 0;

            virtual void recalculate_path() = 0;
    };
}